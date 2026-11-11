#include <bits/stdc++.h>
using namespace std;
int n,m,x,o,l[31],sum[31],ans,len;
bool a[200001][31];
queue<int> q;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	l[0]=1;
	for(int i=1;i<=30;i++)l[i]=l[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>x;
		o=0;
		while(x>0){
			if(x%2==1)a[i][o]=true,sum[o]++;
			o++,x/=2;
		}
		q.push(i);
	}
	for(int i=30;i>=0;i--){
		if(sum[i]<m)continue;
		len=q.size();
		while(len--){
			o=q.front();
			q.pop();
			if(a[o][i])q.push(o);
		}
		if(q.size()<m)break;
		ans+=l[i];
	}
	cout<<ans;
	return 0;
}
