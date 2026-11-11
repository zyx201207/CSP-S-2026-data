#include<bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010],l=0,ans=0;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l=l+a[i];
		b[i]=l;
	}
	int s=0;
	for(int i=1;i<=n;i++){
		if(s>=l/2) break;
		int m=l+1-a[i];
		for(int j=n;j>=1;j--){
			if((b[j]-a[j]+1)>m){
				if(c[j]!=c[i]) ans+=a[j];
				continue;
			}
			if((b[j]-a[j]+1)<=m){
				if(c[j]==c[i]){
					break;
				}
				else{
					ans+=b[j]-m+1;
					break;
				}
			}
		}
		s+=a[i];
	}
	cout<<ans;
	
	
}
