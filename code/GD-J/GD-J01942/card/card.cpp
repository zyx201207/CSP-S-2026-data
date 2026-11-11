#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N],s[N],t[N],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		cnt=0;
		for(long long j=i;j<=n;j++){
			long long b=a[j],k=j;
			t[++cnt]=a[j];
			j++;
			while(1){
				if(a[j]==b) k=j;
				j++;
				if(j>n) break;
			}
			j=k;
		}
		for(long long j=1;j<=cnt;j++)
			s[t[j]]++;
	}
	for(long long i=1;i<=m;i++)
		cout<<s[i]<<' ';
	return 0;
}
