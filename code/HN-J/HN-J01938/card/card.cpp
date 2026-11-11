#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
bool f[N];
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		deque<int> q;
		for(int j=i;j<=n;j++){
			for(int k=0;k<q.size();k++){
				if(q[k]==a[j]){
					for(int l=k;l<q.size();)q.pop_back();
				}
			}
			q.push_back(a[j]);
		}
		memset(f,0,sizeof(f));
		for(int j=0;j<q.size();j++){
			f[q[j]]=1;
		}
		for(int j=1;j<=m;j++){
			cnt[j]+=f[j];
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}

