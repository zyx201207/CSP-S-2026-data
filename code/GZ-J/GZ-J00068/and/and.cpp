//GZ-J00068，阮辰允，贵阳市白云区华师一学校
#include <bits/stdc++.h>
using namespace std;
int n,m,x,cnt1,ans;
queue<int> q; 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		q.push(x);
	}
	for(int i=30;i>=0;i--){
		int sz=q.size();
		cnt1=0;
		for(int j=1;j<=sz;j++){
			int u=q.front();
			q.pop();
			q.push(u);
			if(u&(1<<i)){
				cnt1++;
			}
		}
		if(cnt1>=m){
			ans+=(1<<i);
			for(int j=1;j<=sz;j++){
				int u=q.front();
				q.pop();
				if(u&(1<<i)){
					q.push(u);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
