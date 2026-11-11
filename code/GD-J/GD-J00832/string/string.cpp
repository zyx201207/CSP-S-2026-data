#include<bits/stdc++.h>
using namespace std;
long long x[1222222];
char y[1222222];
long long n;
long long sz;
long long ans;
long long l=1,r=0,zuo=0,you=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(long long i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	while(l<=r){
		if(x[l]>x[r]){
			x[l]-=x[r];
			if(y[l]!=y[r]){
				ans+=x[r];
			}
			r--;
		}else if(l==r){
			if(y[l]!=y[r]){
				ans+=x[l];
			}
			l++;
			r--;
			
		}else{
			x[r]-=x[l];
			if(y[l]!=y[r]){
				ans+=x[l];
			}
			l++;
		}
	}
	cout<<ans;
	return 0;
}
