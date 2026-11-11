#include<bits/stdc++.h>
using namespace std;
long long n,m,c,v;
long long s[500010],b[500010],x[500010],a[500010],q[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	v=n;
	while(v--){
		for(long long i=n-v;i<=n;i++){
			if(s[a[i]]!=0){
				for(long long j=x[a[i]]+1;j<=c;j++){
					s[b[j]]=0;
				}
				c=x[a[i]];
			}
			else{
				c++;
				s[a[i]]=1;
				x[a[i]]=c;
				b[c]=a[i];
			}
		}
		for(long long i=1;i<=c;i++){
			q[b[i]]++;
		}
		memset(s,0,sizeof(s));
		memset(x,0,sizeof(x));
		memset(b,0,sizeof(b));
	}
	for(long long i=1;i<=m;i++){
		cout<<q[i]<<' ';
	}
}
