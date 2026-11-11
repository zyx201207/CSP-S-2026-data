#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n,m,q;
int be,en;
ll W[500005]; //从第i个站口走到第i个站厅的时间
ll dp[505][505]; //从第i条线路走到第j条线路的最少时间
vector<pair<int,ll>>S[500005];

void File(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}

void Read_Integer(int &num){ 
	num=0;
	char c;
	while(1){
		c=getchar();
		if(c>='0'&&c<='9'){
			break;
		}
	}
	while(c>='0'&&c<='9'){
		num=num*10+int(c-'0');
		c=getchar();
	}
}

void Floyd(){
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for(int bh=1;bh<=m;bh++){
		int len=S[bh].size();
		for(int i=0;i<len-1;i++){
			for(int j=i+1;j<len;j++){
				int l=S[bh][i].first,r=S[bh][j].first;
				ll t1=S[bh][i].second,t2=S[bh][j].second;
				if(l>r){
					swap(l,r);
				}
				dp[l][r]=min(dp[l][r],t1+t2);
				dp[r][l]=min(dp[r][l],t1+t2);
			}
		}
	}
	for(int mid=1;mid<=n;mid++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][mid]+dp[mid][j]);
			}
		}
	}
}

int main(){
	File();
	Read_Integer(n);
	Read_Integer(n);
	Read_Integer(m);
	Read_Integer(q);
	Read_Integer(q);
	for(int i=1,x;i<=m;i++){
		Read_Integer(x);
		W[i]=(ll)x;
	}
	for(int i=1,k;i<=n;i++){
		Read_Integer(k);
		for(int j=1,bh,t;j<=k;j++){
			Read_Integer(bh);
			Read_Integer(t);
			S[bh].push_back({i,(ll)t});
		}
	}
	Floyd();
	while(q--){
		Read_Integer(be);
		Read_Integer(en);
		int s1=S[be].size(),s2=S[en].size();
		ll ans=LLONG_MAX;
		for(int i=0;i<s1;i++){
			for(int j=0;j<s2;j++){
				ll cnt=W[be]+W[en]+S[be][i].second+S[en][j].second;
				int l=S[be][i].first,r=S[en][j].first;
				ans=min(ans,cnt+dp[l][r]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
Green AC
*/
