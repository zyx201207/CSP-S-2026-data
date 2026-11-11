#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=2e5+2;
int n,a[N],x,y,mn;
char c[N];
ll ans;
int main(){
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i]>>c[i];
	for(int i=1,j=n;i<=j;){
		mn=min(a[i]-x,a[j]-y);
		if(i!=j){
			if(c[i]!=c[j]) ans+=mn;
		}else break;
		if(x+mn==a[i]) ++i,x=0;
		else x=mn;
		if(y+mn==a[j]) --j,y=0;
		else y=mn;
	}
	cout<<ans;
	fclose(stdin),fclose(stdout);
	return 0;
}
