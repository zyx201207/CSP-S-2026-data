#include<bits/stdc++.h>
//#define F(i,a,b) for(register int i=a;i<=b;i=-~i)
//#define fre(o) freopen(#o".in","r",stdin),freopen(#o".out","w",stdout)
#define F(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
using namespace std;const int N=2e5+67;
int n,a[N],cnt;char c[N],s[N];
ll k[N],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	F(i,1,n){
		cin>>a[i]>>c[i];
		if(i!=0&&c[i]==c[i-1])k[cnt]+=a[i];
		else{k[++cnt]=a[i];s[cnt]=c[i];}
	}int l=1,r=cnt;
	while(l<r){
		ll mina=min(k[l],k[r]);
		if(s[l]!=s[r])ans+=mina;
		k[l]-=mina,k[r]-=mina;
		if(k[l]==0)l++;
		if(k[r]==0)r--;
	}cout<<ans;
	return 0;
}//100pts
