//GZ-J00238 中央民族大学附属中学贵阳学校  杨忠瀚 
#include<bits/stdc++.h>
using namespace std;
int n,m,x[200005],cnt[200005],com[200005];
queue<int>que;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	int k=1;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		while(!que.empty())que.pop();
		for(int j=i;j<=n;j++){
			if(x[j]==que.()){
				
			}
			que.push(x[j]);
		}
	}
	return 0;
}
