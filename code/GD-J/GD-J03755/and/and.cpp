#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],len,ans=LONG_LONG_MAX;
string b[200005];
bool vis[200005];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		double qp=log2(a[i])+1;
		int p=floor(qp);
		len=max(len,p);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		int p=a[i],j=len;
		while(p>0){
			if(p%2==0)b[i][j]='0',p/=2,j--;
			else b[i][j]='1',p/=2,j--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=len;j++){
			if(!b[i][j])b[i][j]='0';
		}
	}
	for(int i=1;i<=len;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(b[j][i]=='1'&&!vis[j])sum++;
		}
		if((sum<m&&i==len)||(i==len&&sum>m)){
			for(int j=1;j<=n;j++){
				if(m>0&&!vis[j])m--,ans=(ans&a[j]);
			}
			cout<<ans;
			return 0;
		}else if(sum==m){
			for(int j=1;j<=n;j++){
				if(b[j][i]=='1'&&!vis[j])ans=(ans&a[j]);
			}
			cout<<ans;
			return 0;
		}else if(sum>m){
			for(int j=1;j<=n;j++){
				if(b[j][i]=='1'&&!vis[j])vis[j]=0;
				else vis[j]=1;
			}
		}
	}
	return 0;
}
