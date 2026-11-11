#include<bits/stdc++.h>
using namespace std;
int n,aa,c1[200005],c2[200005];
char cinchar;
long long ans,a1[200005],a2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>aa>>cinchar;
		c1[i]=cinchar-'a'+1;
		a1[i]=a1[i-1]+aa;
	}for(int i=1;i<=n;i++){
		a2[i]=a1[n]-a1[n-i];
		c2[i]=c1[n-i+1];
	}int i1=1,i2=1;
	long long overid=0;
	while(i1<=n&&i2<=n){
		if(c1[i1]==c2[i1]){
			overid=min(a1[i1],a2[i2]);
			if(a1[i1]>a2[i2]){
				i2++;
			}else if(a1[i1]==a2[i2]){
				i2++;i1++;
			}else{
				i1++;
			}
		}else{
			ans+=min(a1[i1],a2[i2])-overid;
			overid=min(a1[i1],a2[i2]);
			if(a1[i1]>a2[i2]){
				i2++;
			}else if(a1[i1]==a2[i2]){
				i2++;i1++;
			}else{
				i1++;
			}
		}
	}cout<<ans/2;
}
