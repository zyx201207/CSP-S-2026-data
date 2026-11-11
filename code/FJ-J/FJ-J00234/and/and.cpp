#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,m;
int a[N];
int st[10];

bool check(int u){
	while(u>=2){
		if(u%2==0){
			u/=2;
		}else{
			return false;
		}
	}
	return true;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	bool A=true,B=true,C=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		st[a[i]]++; 
		if(!check(a[i]+1)){
			A=false;
		}
		if(a[i]!=i-1){
			B=false;
		}
		if(a[i]>=4){
			C=false;
		}
	}
	
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n]<<endl;
	}else if(m==2){
		long long mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				mx=max(mx,((long long)a[i]&a[j]));
			}
		}
		cout<<mx<<endl;
	}else if(m==n){
		long long mx=a[1];
		for(int i=1;i<=n;i++){
			mx=(mx&a[i]);
		}
		cout<<mx<<endl;
	}else if(A){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}else if(C){
		if(m<=a[3]){
			cout<<3;
		}else if(m<=st[2]+st[3]){
			cout<<2;
		}else if(m<=st[1]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		sort(a+1,a+1+n);
		long long res=a[n];
		for(int i=n;i>=n-m+1;i--){
			res=(res&a[i]);
		}
	}
	
	
	return 0;
} 
