#include<bits/stdc++.h>
#define int long long
using namespace std;
deque <int> q;
int n,m,cnt[300005],cnt2[300005],ans[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		q.push_back(x);
		cnt[x]++;
	}
	for(int i=1;i<=n;i++){
		deque <int> q2=q;
		for(int j=1;j<=m;j++)cnt2[j]=cnt[j];
		if(i>=2){
			for(int j=1;j<=i-1;j++){
				cnt2[q2.front()]--;
				q2.pop_front();
			}
		}
		deque <int> q3=q2;
	
	for(int j=i;j<=n;j++){
			int x=q3.front();
			q3.pop_front();
			if(cnt2[x]){
				while(q2.back()!=x||cnt2[x]!=1){
					cnt2[q2.back()]--;
					q2.pop_back();
				}
				
			}
			else q2.push_back(x);
		}
		while(!q2.empty()){
			ans[q2.front()]++;
			q2.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
	}
