#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],dp[N],lst[N],ans[N];
deque<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push_back(a[i]);
		if(!dp[a[i]]){
			dp[a[i]]=1;
			lst[a[i]]=i;
		}else{
			int r=lst[a[i]];
			while(q.size()>r){
				dp[q[q.size()-1]]=0;
				if(lst[q[q.size()-1]]==q.size()-1) lst[q[q.size()-1]]=0;
				q.pop_back();
			}
		}
		for(int i=1;i<=m;i++){
			if(dp[i])ans[i]++; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}


