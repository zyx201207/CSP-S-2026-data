#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[32],mx=30,ans; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	queue<int>q;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		for(int j=30;j>=0;j--)if(a&(1<<j))cnt[j]++;
		q.push(a);
	}
	while(q.size()>=m){
		queue<int>q2;
		for(;mx>=0&&cnt[mx]<m;mx--);//最大的位 
		if(cnt[mx]>=m)ans+=(1<<mx);
		if(mx==0)break;//只剩最后一位 
		memset(cnt,0,sizeof(cnt));//重置 
		while(!q.empty()){
			int x=q.front();
			q.pop(); 
			if(x&(1<<mx)){//该位不符合 
				q2.push(x);
				for(int j=mx-1;j>=0;j--)if(x&(1<<j))cnt[j]++;
			}
		}//全部查一遍 
		swap(q,q2);//能用的存进去 
	}
	cout<<ans;
	return 0;
}
