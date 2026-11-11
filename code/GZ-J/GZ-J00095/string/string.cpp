// GZ-J00095 贵阳市白云区华师一学校 王舒越 
#include<bits/stdc++.h>
#define ll long long
#define MAXN 200010
using namespace std;
ll k,n,len,f,lenf,ans,a[MAXN];
char c[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>k;
	for(ll i=1,x;i<=k;i++){
		char y;
		cin>>x>>y,len+=x;
		if(i==1) a[++n]=x,c[n]=y;
		else if(y==c[n]) a[n]+=x;
		else a[++n]=x,c[n]=y;
	}
	for(ll i=1,j=n;;){
		if(f==1 || i>=j) break;
		ll x=min(a[i],a[j]);
		if(lenf+x>len/2) x=len/2-lenf,f=1;
		a[i]-=x,a[j]-=x,lenf+=x;
		if(c[i]!=c[j]) ans+=x;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<ans;
	return 0;
}
