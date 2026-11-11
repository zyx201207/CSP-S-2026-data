#include<bits/stdc++.h>
using namespace std;
int n,m,a[55555],sum[55555];
bool book[55555];
stack<int>s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card3.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(book,0,sizeof(book));
		for(int j=i;j<=n;j++){
			if(book[a[j]]){
				while(!s.empty()){
					if(s.top()==a[j])break;
					else{
						book[s.top()]=0;
						s.pop();
					}
				}
			}else{
				s.push(a[j]);
				book[a[j]]=1;
			}
		}
		while(!s.empty()){
			sum[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<' ';
	return 0;
}
