#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],f=1,g,ans,r;
char b[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if (a[i]==a[1]&&f==1) f=1;
		else f=0;
	}
	for(int i=1;i<=n;i++){
		if (b[i]==b[1]) g=1;
		else {
			g=0;
			r=i;
			break;
		}
	}
	for(int i=r;i<=n;i++){
			if (b[i]==b[r]) r=1;
			else{
				r=0;
				break;
			}
		}
	if (g==1) {
		cout<<0;
		return 0;
	}
	else {
		for(int i=r+1;i<=n;i++){
			ans+=a[i];
		}
		if (r==1){
			cout<<ans;
			return 0;
		}
		if ((ans/2)%2==0&&r!=1) {
			cout<<ans/2;
		}
		else cout<<ans/2+1;
	}
	return 0;
} 
