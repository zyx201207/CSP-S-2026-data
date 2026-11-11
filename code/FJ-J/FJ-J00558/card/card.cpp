#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10000005],d[10000005],b[10000005],c[10000005],y;
long long f(long long x){
	for(int j=1;j<=m;j++){
		b[j]=0;
	}
	queue<int> q;
	for(long long j=x;j<=n;j++){
		if(b[a[j]]==0){
			b[a[j]]++;
			q.push(a[j]);
			c[a[j]]=j;
		}else{
			y=1;
			while(y<=c[a[j]]){
				b[q.front()]=0;
				c[q.front()]=q.size();
				q.pop();
				y++;
			}
			q.push(a[j]);
			b[a[j]]=1;
			c[a[j]]=j;
		}
	}
	for(int j=1;j<=m;j++){
		if(b[j]>0){
			d[j]++;
		}
	}
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		f(i);
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
