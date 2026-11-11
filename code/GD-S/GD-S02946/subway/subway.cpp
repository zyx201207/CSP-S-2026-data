#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[505],a[505][50005],t[505][50005],o[505][50005];
long long s[5005][5005];
long long op[5005];
long long find(long long s1,long long s2){
	long long minn=199999999;
	if(s1==s2)return 0;
	for(int i=1;i<=m;i++){
		if(s[s1][i]<10000&&op[i]!=1){
			op[i]=1;
			minn=min(find(i,s2)+s[s1][i],minn);
			op[i]=0;
		}
	}
	return minn;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=5000;i++)for(int j=1;j<=5000;j++)s[i][j]=10000;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		int l,p;
		cin>>l;
		a[i][0]=l;
		for(int j=1;j<=l;j++){
			cin>>p;
			cin>>a[i][p];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]){
				for(int u=1;u<=m;u++){
					if(i!=u&&a[j][u])s[i][u]=min(s[i][u],a[j][u]+a[j][i]);
					//if(i==2&&j==2&&u==2)cout<<t[j][u]<<" "<<t[j][i]<<endl;
				}
			}
		}
	}//for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)cout<<i<<"-"<<j<<":"<<s[i][j]<<endl; 
	for(int i=1;i<=q;i++){
		int s1,s2;
		cin>>s1>>s2;
		cout<<find(s1,s2)+w[s1]+w[s2]<<endl;
	}
} 
