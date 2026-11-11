#include<bits/stdc++.h>
using namespace std;
long long ans,k,s[200000+5],n,m,x,f[60];
string a[200000+5];
void check(long long mi){
	int sum=0;
	for(int i=1;i<=k;i++)
		sum+=(a[s[i]][mi]-'0');
	if(sum<m) return ;
	int su=0;
	for(int i=1;i<=k;i++){
		if(a[s[i]][mi]=='1')
			su++,s[su]=s[i];
	}
	k=su;
	ans+=(1<<mi);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m),k=n;
	for(int i=1;i<=n;i++)
		s[i]=i;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		string s="";
		while(x){
			s+=char(x%2+'0');
			x/=2; 
		}
		for(int j=0;j<s.size();j++)
			f[j]+=(s[j]-'0');
		a[i]=s;
	}
	for(int i=1;i<=n;i++)
		for(int j=a[i].size();j<=40;j++)
			a[i]+='0';
	for(int i=40;i>=0;i--){
		if(f[i]>=m)
			check(i);
	}
	printf("%lld",ans);
	return 0;
} 
