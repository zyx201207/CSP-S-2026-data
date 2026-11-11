#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N],n,m,sum[N];
stack<long long> s; 
bool f[N]; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int i=0;
	while(++i<=n){
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==1){
				while(s.top()!=a[j]){
					f[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(a[j]);
				f[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(f[j]==1) sum[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
	return 0;
}
