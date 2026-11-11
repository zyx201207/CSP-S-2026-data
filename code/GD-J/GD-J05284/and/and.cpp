#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200050],ans;
bool ct[200050][40];
long long lt[40];

void f1(long long x,int k){
	int  i = 0;
	while(x){
		if(x & 1){
			ct[k][i] = 1;
			lt[i]++;
		}
		i++;
		x >>= 1;
	}
}

void f2(long long x,int k){
	for(int i=0;i<32;i++){
		if(ct[k][i] == 1){
			lt[i]--;
			ct[k][i] = 0;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		f1(a[i],i);
	}
	for(int i = 32;i>=0;i--){
		if(lt[i] >= m){
			ans = ans | (1<<i);
			for(int j = 0;j<n;j++){
				if(ct[j][i] == 0){
					f2(a[j],j);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}


