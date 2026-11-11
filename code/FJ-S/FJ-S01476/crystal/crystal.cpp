#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const int N=5e5+7;
void in(ll &k){
	k=0;
	int f=1;
	char c=getchar();
	while(!((c>='0'&&c<='9')||c=='-')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	k*=f;
	return;
}
void int_in(int &k){
	k=0;
	int f=1;
	char c=getchar();
	while(!((c>='0'&&c<='9')||c=='-')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	k*=f;
	return;
}
int n,l,r,ans;
ll m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int_in(n);in(m);
	for(int i=1;i<=n;i++) in(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	r=0;
	for(l=1;l<=n;l++){
		while(((r+1-l+1)*a[r+1])-(s[r+1]-s[l-1])<=m&&r<n) r++;
		ans=max(ans,r-l+1);
	}
	printf("%d\n",ans);
	return 0;
}
