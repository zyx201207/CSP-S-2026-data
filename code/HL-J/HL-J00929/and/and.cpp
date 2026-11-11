#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int sum[100];
int vis[N];
struct node{
	long long num;
	int wei;
	vector<int>er;
}a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	int max_wei=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		int p=a[i].num;
		int cnt=1;
		while(p){
			a[i].er.push_back(p%2);
			p/=2;
			cnt++;
		}
		a[i].wei=cnt;
		max_wei=max(max_wei,cnt);
	}
	vector<node>vec;
	for(int i=1;i<=n;i++){
		vec.push_back(a[i]);
	}
	while(max_wei>0){
		memset(sum,0,sizeof(sum));
		for(int i=0;i<vec.size();i++){
			for(int j=0;j<vec[i].er.size();j++){
				if(vec[i].er[j])sum[j+1]++;
			}
		}
		
		bool flag=true;
		for(int i=max_wei;i>=1;i--){
			if(vis[i])continue;
			vis[i]=1;
			if(sum[i]>=m){
				max_wei=i;
				break;
			}
			if(i==1&&flag==true){
				flag=false;break;
			}
		}
		if(!flag)break;
		vector<node>vec2;
		for(auto it:vec){
			if(it.wei<max_wei)continue;
			if(it.er[max_wei-1]==1)vec2.push_back(it);
		}
		vec=vec2;
}
	long long ans=vec[0].num;
	for(int i=1;i<m;i++)ans=ans&vec[i].num;
	cout<<ans;
}