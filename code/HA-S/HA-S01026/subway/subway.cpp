#include<bits/stdc++.h>
using namespace std;

int test_id,n,m,d,question;
long long w[10004];
struct bian{
	long long id,pay;
};
vector<bian> t[10004];
bool f[10004];
long long sp[10004][10004];

void dj(int st){
	for (int i=st;i<=m;i++) f[i]=0;
	sp[st][st]=0;
	for (int i=st;i<=m;i++){
		long long minn=1e18,idm=-1;
		for (int j=st;j<=m;j++){
			if(minn>sp[st][j] && f[j]==0){
				minn=sp[st][j];
				idm=j;
			}
		}
		f[idm]=1;
		for (auto j:t[idm]){
			sp[st][j.id]=min(sp[st][j.id],sp[st][idm]+j.pay);
		}
	}
}

int main(){
//	freopen("subway4.in","r",stdin);
//	freopen("subway.out","w",stdout);
	
	cin>>test_id>>n>>m>>d>>question;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		int id1,id2,pay1,pay2;
		cin>>id1>>pay1>>id2>>pay2;
		t[id1].push_back({id2,pay1+pay2});
		t[id2].push_back({id1,pay1+pay2});
	}
	
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++){	
			sp[i][j]=1e18;
		}
	}
	while(question--){
		long long sum_time_walk=0;
		int start_id,end_id;
		cin>>start_id>>end_id;
		sum_time_walk+=w[start_id]+w[end_id];
		if(start_id>end_id){
			int temp=end_id;
			end_id=start_id;
			start_id=temp;
		}
		dj(start_id);
		cout<<sum_time_walk+sp[start_id][end_id]<<"\n";
	}
	
	
	
	
	return 0;
}