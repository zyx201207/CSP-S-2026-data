#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;
int n,m;
string a[200005];
short b[200005][15];
bool c[200005][35];
int www[200005];
int m_2[35];
void chu(int x,int i,int num){
	int jw=0;
	for(int j=x;j<=num;++j){
		b[i][j]+=jw*10;
		jw=b[i][j]%2;
		b[i][j]/=2;
	}
}
void cun(int i){
	int num=a[i].size();
	int x=1;
	int j=0;
	while(x<=num){
		c[i][++j]=b[i][num]%2;
		if(b[i][x]/2==0) ++x;
		chu(x-1,i,num);
	}
	www[i]=j;
}
int zc[35];
long long ans=LONG_MIN;
void dfs(int i,int ww){
	for(int j=i+1;j<=n;++j){
		for(int k=1,l=1;k<=ww&&l<=www[j];++k,++l){
			if(zc[k]==0||c[j][l]==0) zc[k]=0;
			else zc[k]=1;
		}
		if(i<m) dfs(i+1,min(ww,www[j]));
		else{
			long long sum=0;
			int shu=min(ww,www[j]);
			double chang=0.5;
			for(int k=1;k<=shu;++k){
				chang*=2;
				if(zc[k]==1) sum+=chang;
			}
			ans=max(ans,sum);
		}
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		int w=a[i].size();
		for(int j=0;j<w;++j) b[i][j+1]=a[i][j]-'0';
		cun(i);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=www[i];++j) zc[j]=c[i][j];
		dfs(i,www[i]);
	}
	cout<<ans;
	return 0;
}
