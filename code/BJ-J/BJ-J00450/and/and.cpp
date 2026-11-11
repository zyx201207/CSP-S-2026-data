#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

int n,m;
int a[200005];


vector<int>v;

int cn[33];//meiwei'you'duoshao'ge
bool c[33];

int awy(int x,int y){
	int ans;
	int cnt=1;
	while(x>0&&y>0){
		if(x%2==1&&x%2==y%2){
			ans+=cnt;
		}
		cnt*=2;
		x/=2;y/=2;
	}
	return ans;
}

void zhuan(int a,int i){
	int cnt=1;
	while(a>0){
		if(a%2==1){
			//g[i].p[cnt]=1;
			cn[cnt]++;
		}
		cnt++;
		a/=2;
	}
	cn[0]=max(cn[0],cnt);
}
int ans1=0;
int ansn=0;
int ans2=0;
int ans15=0;
int ansm=0;
bool xz[200005];
int dfs(int i,int cmp){
	if(i==n)return cmp;
	xz[i]=1;
	int ans1= dfs(i+1,awy(cmp,a[i]));
	xz[i]=0;
	int ans2= dfs(i+1,cmp);
	return max(ans1,ans2);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i = 1;i<=n;i++){//shu'ru'
		cin>>a[i];
		ans1=max(ans1,a[i]);
		if(i>1)ansn=awy(ansn,a[i]);
		else ansn=a[i];
		zhuan(a[i],i);
	}
	if(m==1){
		cout<<ans1;
		return 0;
	}
	if(m==n){
		cout<<ansn;
		return 0;
	}
	ans2=0;
	if(m==2){
		ans2=0;
		for(int i = 1;i<n;i++){
			for(int j = i+1;j<=n;j++){
				ans2=max(ans2,awy(a[i],a[j]));
				cout<<ans2<<' ';
			}
		}
		cout<<ans2;
		return 0;
	}
	
		cout<<dfs(1,(1024*1024-1));
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
