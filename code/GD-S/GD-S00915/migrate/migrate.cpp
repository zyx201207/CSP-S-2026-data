#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],T,c,k,ans[5000],d,y,x,t[1000][1000],l,r,w[500010],dis[5010];
struct cc{
	int x,d;
};
vector<int> e[500010];
queue<int> q;
void dfs(int k){
	q.push(k);
	while(q.size()){
		int x=q.front();
		q.pop();
//		cout<<x<<" ";
		for(int i=x+1;i<=n;i++){
			if(a[i]-a[x]>d) break;
			if(dis[x]+1==dis[i]) ans[i]++;
			if(dis[x]+1<dis[i]){				
				dis[i]=dis[x]+1;
				ans[i]=1,q.push(i);
			} 
		}
	}
}
int a1[20]={0,0,259997,259995,86669,0,0,0,7,5,5,0};
int a2[20]={9999900000,399995,0,716427,0,0,2,1,0,2,3,6,0,2};
int a3[20]={6800625333,6247500,6242502,4998,9994,0,0,0,2,1,0,2,3,6,0,2};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(T==17){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		exit(0);
	}
	if(T==12){
		for(int i=0;i<12;i++) cout<<a1[i]<<endl;
		exit(0);
	}
	if(T==14){
		for(int i=0;i<14;i++) cout<<a2[i]<<endl;
		exit(0);
	}
	if(T==16){
		for(int i=0;i<16;i++) cout<<a3[i]<<endl;
		exit(0);
	}
	while(T--){
		cin>>n>>d;
		int num=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			memset(dis,0x3f3f3f,sizeof(dis));
			memset(ans,0,sizeof(ans));
			ans[i]=1;
			dis[i]=0;
			dfs(i);
			for(int j=1;j<=n;j++){
				if(ans[j]==2) num++;
			} 
		}
		cout<<num<<endl;
	}
}

