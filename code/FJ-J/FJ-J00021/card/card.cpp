#include<bits/stdc++.h>
using namespace std;
int n,m,a[510000],nowvis[310000],vis[310000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int>s;
		for(int j=i;j<=n;j++){
			if(nowvis[a[j]]!=0){
				for(;;){
					if(s.empty())break;
					if(s.top()==a[j])break;
					nowvis[s.top()]=0;
					s.pop();
				}
			}
			else {
				nowvis[a[j]]=1;
				s.push(a[j]);
			}
		}
		for(;;){
			if(s.empty()){
				break;
			}
			vis[s.top()]++;
			s.pop();
		}
		for(int j=1;j<=m;j++){
			nowvis[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
}
