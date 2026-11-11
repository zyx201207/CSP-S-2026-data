#include<bits/stdc++.h> 
using namespace std;
int n,a[200001];
long long ans=0,cnt=0;
char s[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>s[i];
	for(int i=1;i<=n;i++)
		cnt+=a[i];
	for(int i=1,j=n;i<=n;i++,j--){
		if(s[i]!=s[j]){
			if(a[i-1]!=0){
				if(s[i-1]!=s[j])
					ans+=a[i-1];
				a[j]-=a[i-1];
			}
			if(a[j+1]!=0){
				if(s[j+1]!=s[i])
					ans+=a[j+1];
				a[i]-=a[j+1];
			}
			ans+=min(a[i],a[j]);
			if(a[j]>=a[i])
				a[j]-=a[i];
			else
				a[i]-=a[j];
		}
		else{
			if(a[i-1]!=0){
				if(s[i-1]!=s[j])
					ans+=a[i-1];
				a[j]-=a[i-1];
			}
			if(a[j+1]!=0){
				if(s[j+1]!=s[i])
					ans+=a[j+1];
				a[i]-=a[j+1];
			}
			a[i]-=min(a[i],a[j]);
			a[j]-=min(a[i],a[j]);
		}
	}
	cout<<ans/2<<"\n";
	return 0;
}
