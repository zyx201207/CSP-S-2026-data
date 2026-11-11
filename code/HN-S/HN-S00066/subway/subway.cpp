#include<bits/stdc++.h>
using namespace std;
long long w[500000],t[500000][20],have[500000][21],best[500][500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(best,-1,sizeof(best));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
		cin>>w[i];
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int sta;
			cin>>sta;
			sta--;
			have[sta][0]++;
			int id=have[sta][0];
			cin>>t[sta][id];
			have[sta][id]=i;
			for(int p=1;p<id;p++){
				if(best[i][have[sta][p]]==-1)
					best[i][have[sta][p]]=t[sta][id]+t[sta][p];
				else
					best[i][have[sta][p]]=min(t[sta][id]+t[sta][p],best[i][have[sta][p]]);
				best[have[sta][p]][i]=best[i][have[sta][p]];
			}
		}
		best[i][i]=0;
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			if(best[i][k]==-1) continue;
			for(int j=0;j<n;j++){
				if(best[k][j]==-1) continue;
				if(best[i][j]==-1) best[i][j]=best[i][k]+best[k][j];
				else best[i][j]=min(best[i][k]+best[k][j],best[i][j]);
			}
		}
	}
	for(int i=0;i<q;i++){
		long long ans=-1;
		int st,ed;
		cin>>st>>ed;
		st--,ed--;
		for(int j=1;j<=have[st][0];j++){
			for(int k=1;k<=have[ed][0];k++){
				long long temp=t[st][j]+t[ed][k];
				temp+=best[have[st][j]][have[ed][k]];
				if(ans==-1) ans=temp;
				else ans=min(ans,temp);
			}
		}
		ans=ans+w[st]+w[ed];
		cout<<ans<<endl;
	}
	return 0;
} 
