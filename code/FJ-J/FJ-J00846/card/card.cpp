#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],p[300005];
deque<int> q;
void clr1(){
	while(!q.empty()){
		q.pop_back();
	}
	return;
}
void clr2(int x){
	while(q.back()!=x){
		p[q.back()]=0;
		q.pop_back();
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++){
		memset(p,0,sizeof(p));
		clr1();
		for (int j=i;j<=n;j++){
			if (!p[a[j]]){
				q.push_back(a[j]);
				p[a[j]]=1;
			}
			else{
				clr2(a[j]);
			}
		}
		for (int j=1;j<=m;j++){
			if (p[j])ans[j]++;
		}
	}
	for (int i=1;i<=m;i++)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
