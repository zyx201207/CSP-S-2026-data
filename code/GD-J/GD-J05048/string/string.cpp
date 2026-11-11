#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,num,ans=0,l,r,i,j;
char letter;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<ll> a(n+5),c(n+5);
	for(int i=0;i<n;++i){
		cin>>num;
		cin>>letter;
		a[i]=num;
		c[i]=letter;
	}
	i=0;j=n-1;
	l=a[i];r=a[j];
	while(i<j){
		if(c[i]!=c[j]){
			if(a[i]==a[j]){
				ans+=a[i];
				++i;--j;
				continue;
			}else if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				a[j]=0;
				--j;
			}else{
				ans+=a[i];
				a[j]-=a[i];
				a[i]=0;
				++i;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=0;
				--j;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				a[i]=0;
				++i;
			}else{
				++i;
				--j;
			}
		}
	}
	cout<<ans;
	return 0;
}
