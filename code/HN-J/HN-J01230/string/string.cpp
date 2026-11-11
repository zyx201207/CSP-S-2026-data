#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long o,a[200005],ans=0;
	char b[200005];
	cin>>o;
	for(int i=1;i<=o;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=o/2;i++){
		if(a[i]!=a[o-i+1]&&b[i]==b[o-i+1]){
			ans+=max(a[i]-a[o-i+1],a[o-i+1]-a[i]);
			a[i+1]-=max(a[i]-a[o-i+1],a[o-i+1]-a[i]);
		}else{
			if(a[i]==a[o-i+1]&&b[i]!=b[o-i+1]){
				ans+=a[i];
			}else{
				if(b[i]!=b[o-i+1]&&a[i]!=a[o-i+1]){
					ans+=max(a[i],a[o-i+1]);
					a[i+1]-=max(a[i]-a[o-i+1],a[o-i+1]-a[i]);
				}
				
			}
		}
	}
	cout<<ans;
	return 0;
}
