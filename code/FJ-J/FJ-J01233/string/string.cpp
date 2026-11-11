#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],tot,mid,ans,d1,d2,s1,s2;
char c[200005];
string s;
bool f,num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		tot+=a[i];
		if(a[i]!=a[1]) num=1;
		if(c[i]!=c[1]) f=1;
	}
	if(!f){
		cout<<0;
		return 0;
	}
	if(!num){
		for(int i=1;i<=n;i++) s+=c[i];
		tot=n;
		mid=(tot+1)/2-1;
		for(int i=0;i<=mid;i++){
			if(s[i]!=s[tot-i-1]) ans++;
		}
		cout<<ans*a[1];
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	mid=(tot+1)/2-1;
	for(int i=0;i<=mid;i++){
		if(s[i]!=s[tot-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
