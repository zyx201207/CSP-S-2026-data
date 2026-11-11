#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,l,r,ans,a[N];
char c[N];
ll read(){
	char ch;ll s=0,w=1;
	while((ch=getchar())>'9' || ch<'0') if(ch=='-') w=-1;
	while(ch>='0' && ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),cin>>c[i];
	}
	l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]==a[r]){
				l++,r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++,r--;
			}
			else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
