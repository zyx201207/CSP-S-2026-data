#include<bits/stdc++.h>
using namespace std;
#define int long long
int jz[200005][31],n,ans,sum,m,ans1;
queue<int>q;
queue<int>q1;
queue<int>q2;
void zh(int x,int y){
	int t=0;
	while(x){
		jz[y][t]=(x&1);
		x=x>>1;
		t++;
	}
	ans=max(ans,t-1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1,a;i<=n;i++){
		cin>>a;
		zh(a,i);
		q.push(i);
	}
//	for(int i=1,a;i<=n;i++){
//		for(int j=ans;j>=0;j--){
//			if(jz[i][j]==1||jz[i][j]==0)cout<<jz[i][j];
//			else cout<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=ans;i>=0;i--){
		ans1=0;
		//cout<<endl;
		while(!q.empty()){
			//cout<<q.front()<<" ";
			if(jz[q.front()][i]&1){
				q2.push(q.front());
				ans1++;
			}
			else q1.push(q.front());
			q.pop();
		}
		while(!q2.empty()){
			q.push(q2.front());
			q2.pop();
		}
		//cout<<ans1<<" "<<i<<endl;
		if(ans1>=m){
			sum+=pow(2,i);
			while(!q1.empty())q1.pop();
		}
		else if(ans1<m){
			while(!q1.empty()){
				q.push(q1.front());
				q1.pop();
			}
		}
	}
	cout<<sum;
} 

