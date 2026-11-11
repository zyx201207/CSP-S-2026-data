#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1111111],ans,maxn=-2e9,e[1111111];
string b[1111111],c[1111111];
bool d[1111111];
void ss(long long start,long long cc){
	if(cc==m){
		for(int i=0;i<b[e[1]].size();i++) c[1][i]=b[e[1]][i];
		for(int i=2;i<=cc;i++) for(int j=0;j<max(b[e[i]].size(),c[1].size());j++) if(b[e[i]][j]!=c[1][j]) c[1][j]=0;
		for(int i=0;i<c[1].size();i++) if(c[1][i]!=0) ans+=pow(2,c[1].size()-i-1);
		maxn=max(maxn,ans);
		ans=0;
		memset(c,0,sizeof(c));
		return ;
	}
	for(int i=start+1;i<=n;i++){
		if(d[i]==0){
			d[i]=1;
			cc++;
			e[cc]=i;
			ss(i,cc);
			d[i]=0;
			e[cc]=0;
			cc--;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long h=a[i];
		while(h){
			b[i]+=(h%2+'0');
			h/=2;
		}
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	ss(1,0);
	cout<<maxn;
	return 0;
}
