#include<bits/stdc++.h>
using namespace std;

bool roads[110][110];
vector<int> roads2[110];
long long n,k;
int arr[110];
bool record[110];
int ans;

bool check(){
	int cnt=0;
	for (int i=0;i<k;i++){
		for (int j=i+1;j<k;j++){
			if (roads[arr[i]][arr[j]]){
				cnt++;
			}
			if (cnt>3){
				return false;
			}
		}
	}
	return true;
}

int run(){
	int cnt=0;
	for (int i=1;i<=n;i++){
		if (record[i]==false){
			int cnt2=0;
			deque<pair<int,int>> q;
			q.push_back(make_pair(i,0));
			while (!q.empty()){
				auto u=q.front(); 
//				int u=q.front.first,temp=u.front().second;
				q.pop_front();
				for (auto v:roads[u.first]){
					if (record[v]){
						cnt2=u.second+1;
						break;
					} 
					q.push_back(make_pair(v,u.second+1));
				}
				if (cnt2!=0){
					break;
				}
			}
			cnt=max(cnt2,cnt);
		}
	}
	return cnt;
}

void dfs(int num,int id){
	if (num==k){
		cout<<"1";
		if (check()){
			cout<<"2";
			ans=min(ans,run());
		}
		return ;
	}
	for (int i=id+1;i<n;i++){
		arr[num]=i;
		record[i]=true;
		dfs(num+1,i);
		record[i]=false;
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c,t;
	cin>>c>>t;
	while (t--){
		ans=0x3f3f3f3f;
		memset(roads,false,sizeof(roads));
		for (long long i=1;i<=100;i++){
			memset(roads2,0,sizeof(roads2));
		}
		memset(arr,0,sizeof(arr));
		memset(record,false,sizeof(record));
		cin>>n>>k;
		for (long long i=1;i<=n-1;i++){
			long long u,v;
			cin>>u>>v;
			roads[u][v]=roads[v][u]=true;
			roads2[u].push_back(v);
		}
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}
