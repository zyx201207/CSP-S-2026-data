include<bits/stdc++.h>
using namespace std;
long long n,m;
const int maxn=5e5+10;
long long a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i};
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;i++){
			q.push(a[j]);
			p[a[j]]>1){
				do{
					q.pop();
				}while(q.top()!=a[j]);
				p[u]++;
				q.push(a[j]);
			}
		}
		Sort(t,t+n,cmp);
		for(int i=1;i<=n;i++){
			if(t[i])cout<<i<<" ";
		}
	return 0;
}
