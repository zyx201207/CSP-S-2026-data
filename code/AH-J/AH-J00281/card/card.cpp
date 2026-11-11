#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[500005],s[300005],ans[300005];
deque<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int k=a[j];
			if(s[k]==0){
				q.push_front(k);
				s[k]=1;
			}
			else if(s[k]==1){
				while(q.front()!=k){
					s[q.front()]--;
					q.pop_front();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(s[j]==1){
				ans[j]++;
			}
			s[j]=0;
		}
		q.clear();
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
