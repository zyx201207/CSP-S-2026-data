#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
stack<int> s;
int a[N],f[M],b[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		while(!s.empty())s.pop();
		memset(f,0,sizeof(f));
		for(int j=1+(i-1);j<=n;j++){
		    while(f[a[j]]){
				f[s.top()]--;
				s.pop();
			}
			s.push(a[j]);
			f[a[j]]++;
		}
		for(int j=1;j<=M;j++)
			if(f[j])b[j]++;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
}
