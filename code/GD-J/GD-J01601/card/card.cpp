#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],ans[N];
int find(vector<int>v,int target){
	int l=0,r=v.size()-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(v[mid]==target) return mid;
		if(v[mid]<target) l=mid+1;
		else r=mid;
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			flag=false;
		} 
	}
	if(flag){
		int sum[N]={0},ton[N]={0};
		set<int>st;
		for(int i=1;i<=n;i++){
			st.insert(a[i]);
		}
		for(int i=1;i<=n;i++){
			ton[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			sum[i]=sum[i-1]+ton[i];
		}
		for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		bool vis[N]={0};
		deque<int>q;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				if(q.size()&&q.back()==a[j]) continue;
				while(q.size()&&q.back()!=a[j]){
					vis[q.back()]=false;
					q.pop_back();
				}
			}else{
				vis[a[j]]=1;
				q.push_back(a[j]);
			}
		}
		while(q.size()){
			ans[q.back()]++;
			q.pop_back();
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
