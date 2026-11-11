#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a[200010];
char c[200010];
int nodel=1,noder,sl,sr,dcl,cln;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	noder=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	while(nodel<noder){
		if(sl==0) sl=a[nodel];
		if(sr==0) sr=a[noder];
		if(sl<sr){
			if(c[nodel]!=c[noder]){
				ans+=sl;
				sr-=sl;
				sl=0;
				nodel++;
			}
			else{
				sr-=sl;
				sl=0;
				nodel++;
			}
		}
		else if(sr<sl){
			if(c[nodel]!=c[noder]){
				ans+=sr;
				sl-=sr;
				sr=0;
				noder--;
			}
			else{
				sl-=sr;
				sr=0;
				noder--;
			}
		}
		else{
			if(c[nodel]!=c[noder]){
				ans+=sr;
				sl=0,sr=0;
				nodel++,noder--;
			}
			else{
				sl=0,sr=0;
				nodel++,noder--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
