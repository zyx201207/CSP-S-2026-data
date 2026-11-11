#include<bits/stdc++.h>
using namespace std;
int n,j=1;
long long a[200009],minn=0,maxx=0,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	while(n!=j){
		if(s[j]==s[n-j]){
			if(a[j]==a[n-j]){
				n--;
				j++;
				continue;
			}else if(min(a[j],a[n-j])==a[j]){
				minn=j;
				a[n-j]=max(a[j],a[n-j])-min(a[j],a[n-j]);
			}else{
				minn=n-j;
				a[j]=max(a[j],a[n-j])-min(a[j],a[n-j]);
			}
			if(minn==n-j){
				n--;
			}else{
				j++;
			}
		}else{
			if(a[j]==a[n-j]){
				ans+=a[minn];
				n--;
				j++;
				continue;
			}else if(min(a[j],a[n-j])==a[j]){
				minn=j;
				a[n-j]=max(a[j],a[n-j])-min(a[j],a[n-j]);
			}else{
				minn=n-j;
				a[j]=max(a[j],a[n-j])-min(a[j],a[n-j]);
			}
			ans+=a[minn];
			if(minn==n-j){
				n--;
			}else{
				j++;
			}
		}
	}
	cout<<ans;
	return 0;
}
