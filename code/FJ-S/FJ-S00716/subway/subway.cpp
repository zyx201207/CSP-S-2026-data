#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],k[505],dp[505][505],lin[505],shi[505],ru[505],jie[505][505];vector<pair<int,int>> v[505];
vector<pair<int,int>> g[505];
bool f[505];
int guilei(int qq,int ww,int h2){
	int sum=0;
	bool q1=1,q2=1;
	for(auto vv:v[h2]){
		if(vv.first==qq)sum+=vv.second,q1=0;
		if(vv.first==ww)sum+=vv.second,q2=0;
		if(q1==0&&q2==0)break;
	}
//	cout<<qq<<' '<<ww<<' '<<h2<<' '<<sum<<endl;
	return sum;
}
int lei(int qq,int h2){
	int sum=0;
	bool q1=1;
	for(auto vv:v[h2]){
		if(vv.first==qq)sum+=vv.second,q1=0;
		//if(vv.first==ww)sum+=vv.second,q2=0;
		if(q1==0)break;
	}
//	cout<<qq<<' '<<ww<<' '<<h2<<' '<<sum<<endl;
	return sum;
}
void zhuan(int h1,int h2){
	f[h2]=1;
	//cout<<h2<<endl;
	for(auto vv:g[h2]){
		int k1=vv.first,k2=vv.second;
		//cout<<k1<<' '<<k2<<'\n';
		if(f[k2])continue;
		if(h1==k1){
			zhuan(k1,k2);
			for(int i=1;i<=m;++i){
				dp[h2][i]=min(dp[h2][i],dp[k2][i]);
				//jie[h2][i]=min(jie[h2][i],jie[k2][i]+lei());
				//if(h2==3&&i==3)cout<<k2<<"gun";
			}
//			for(int i=1;i<=m;++i){
//				jie[h2][i]=min(dp[h2][i],dp[h2][i]+lei(h1,h2));
//			}
			//f[k2]=1;
		}else {
			zhuan(k1,k2);
			for(int i=1;i<=m;++i){
				int aaa=guilei(h1,k1,h2);
				dp[h2][i]=min(dp[h2][i],aaa+dp[k2][i]);
				//jie[i][h2]=min(dp[i][h2],aaa+dp[i][h2]+lei());
				//if(h2==3&&i==3)cout<<k2<<"gun";
			}
//			for(int i=1;i<=m;++i){
//				jie[h2][i]=min(dp[h2][i],guilei(h1,k1,h2)+dp[h2][i]+lei(k1,h2));
//			}
			//f[k2]=1;
		}
	}
	for(int i=1;i<=n;++i){
		if(i!=h2)jie[i][h2]+=lei(h1,h2);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	memset(dp,0x3f,sizeof(dp));
	memset(jie,0,sizeof(jie));
	for(int i=1;i<=m;++i)dp[i][i]=0,jie[i][i]=0;
	for(int i=1;i<=n;++i){
		cin>>k[i];
		int aa,ss;
		for(int j=1;j<=k[i];++j){
			cin>>lin[j]>>shi[j];
			v[lin[j]].push_back({i,shi[j]});
			if(j!=1){
				ru[lin[j]]++;
				ru[lin[j-1]]++;
				g[lin[j]].push_back({i,lin[j-1]});
				g[lin[j-1]].push_back({i,lin[j]});
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(ru[i]==1){
			//cout<<i<<"原"; 
			for(auto vv:v[i]){
				memset(f,0,sizeof(f));
				f[i]=1;
			    zhuan(vv.first,i);
			    for(int j=1;j<=m;++j){
			    	if(i!=j)dp[i][j]+=vv.second;
				}
			}//break;
		}//cout<<"gun";
	}
	//cout<<q<<"M";
	int aa,ss;
	while(q--){
		cin>>aa>>ss;
		cout<<dp[aa][ss]+w[aa]+w[ss]+jie[aa][ss]<<"\n";
	}
	return 0;
} //来年再战！ 
