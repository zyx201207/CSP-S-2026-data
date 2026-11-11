#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+7;
int n,m,a[N],la[N],st[N],ans[N];
deque<int> q,qq,pq;
bool bl[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		la[a[i]]=i;
		if(st[a[i]]!=0) st[a[i]]=i;
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			q.push_back(a[i]);
		}
		for(int i=1;i<=n;i++){
			qq=q;
			memset(bl,0,sizeof(bl));
			while(!qq.empty()){
				int cnt=qq.front();
				qq.pop_front();
				if(bl[cnt]){
					while(!pq.empty()&&pq.back()!=cnt){
						bl[pq.back()]=0;
						pq.pop_back();
					}
				}
				else pq.push_back(cnt);
				bl[cnt]=true;
			}
			while(!pq.empty()){
				ans[pq.back()]++;
				pq.pop_back();
			}
			q.pop_front();
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}else{
		for(int i=1;i<=m;i++){
			cout<<la[i]-st[i]+1<<" ";
		}
	}
	return 0;
}
