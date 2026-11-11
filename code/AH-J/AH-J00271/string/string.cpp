#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char s[200005];
long long ans;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		cin>>s[i];
	}
	for(int l=1,r=n;l<r;){
		int x=min(a[l],a[r]);
		ans+=x*(s[l]!=s[r]);
		a[l]-=x;
		a[r]-=x;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans<<endl;
	return 0;
}
