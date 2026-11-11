#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];

int zhuan10(int a){
	int x = 1;
	int sum = 0;
	while(a){
		sum+=(a%10)*x;
		a/=10;
		x*=2;
	}
	return sum;
}

int zhuan2(int a){
	int sum = 0;
	long long x =1;
	while(a){
		sum+=(a%2)*x;
		x *=10;
		a/=2;
	}
	return sum;
} 

int awy(int a,int b){
	int c = 0;
	int x = 1;
	while(a){
		if(a%10 && b % 10){
			c+=1*x;
			x*=10;
			a/=10;
		}else{
			x*=10;
		}
	}
	return c;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn = -1;
	for(int i = 1 ; i <= n ; i ++){
		cin>>a[i];
		max(a[i],maxn);
	}
	if(m == 1){
		cout<<maxn;
		return 0;
	}else if(m == 2){
		for(int i = 1 ; i <= n ; i++){
			for(int j = i + 1 ; j < n ; j ++){
				if(zhuan10(awy(zhuan2(a[i]),zhuan2(a[j]))) > maxn){ 
					maxn = zhuan10(awy(zhuan2(a[i]),zhuan2(a[j])));
				}
			}
		}
	}
	cout<<maxn;
	return 0;
}
