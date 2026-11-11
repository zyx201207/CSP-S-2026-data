#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],ans,ii,jj;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1,x;i<=n;i++){
		char o;
		cin>>x>>o;
		a[i]=x,b[i]=o;
	}
	ii=a[1],jj=a[n];
	for(int i=1,j=n;i<j;){
		if(ii==jj){
			if(b[i]!=b[j]){
				ans+=ii;
			}
			ii=a[++i],jj=a[--j];
		}else if(ii<jj){
			if(b[i]!=b[j]){
				ans+=ii;
			}
			jj-=ii,ii=a[++i];
		}else{
			if(b[i]!=b[j]){
				ans+=jj;
			}
			ii-=jj,jj=a[--j];
		}
	}
	cout<<ans;
	return 0;
}

