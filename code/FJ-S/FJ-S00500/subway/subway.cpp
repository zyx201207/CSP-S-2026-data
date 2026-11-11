#include<bits/stdc++.h>
using namespace std;
int c,n,m,sd,q,w[500005],k[505],ft,tk,kf[505];
long long d[505][505],tkd[505][505],ans;
vector<long long>a[505],t[505],s[500005],f[500005],dija,dijb;
vector<int>lj[505];
void dfs_1(long long qd,long long js,long long wz){
	if(kf[wz]==1){
		ans=min(ans,js);
		return ;
	}int llen=lj[wz].size();
	for(int i=0;i<llen;i++){
		if(lj[wz][i]!=qd)dfs_1(wz,js+1,lj[wz][lj[wz][i]]);
	}return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>sd>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=2000000000;
			if(i==j)d[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int sas,sts;
			cin>>sas>>sts;
			if(ft!=0&&ft!=sts)tk=1;
			ft=sts;
			a[i].push_back(sas);
			t[i].push_back(sts);
			s[sas].push_back(i);
			f[sas].push_back(sts);
		}
	}for(int i=1;i<=n;i++){
		int l=a[i].size();
		for(int j=0;j<l;j++){
			int use=a[i][j],len=s[use].size();
			for(int z=0;z<len;z++){
				d[i][s[use][z]]=min(t[i][j]+f[use][z],d[i][s[use][z]]);
				lj[i].push_back(s[use][z]);
			}
		}
	}for(int i=1;i<=q;i++){
		int rx,ry;
		for(int j=1;j<=n;j++)kf[j]=0;
		cin>>rx>>ry;
		int lenn=s[ry].size();
		for(int j=0;j<lenn;j++){
			kf[s[ry][j]]=1;
		}
		if(tk==0){
			ans=10000000000;
			int lenr=s[rx].size();
			for(int j=0;j<lenr;j++){
				dfs_1(0,0,s[rx][j]);
			}cout<<ans*2*ft+2*ft+w[rx]+w[ry]<<endl;
		}else{
			ans=10000000000;
			int lenr=s[rx].size();
			for(int j=0;j<lenn;j++){
				for(int z=0;z<lenr;z++){
					ans=min(ans,d[s[rx][z]][s[ry][j]]+f[rx][z]+f[ry][j]+w[rx]+w[ry]);
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
} 
