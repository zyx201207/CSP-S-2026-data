#include<bits/stdc++.h>
using namespace std;
long long a[300005];
long long s[300005],q[3000005];
long long n,m;
bool qwer(long long i,long long w){
	int x=1;
	for(long long j=i;j<=n;j++){
		q[x]=s[j];
		x++;
		if(a[s[j]]>0){
			for(long long k=a[s[j]]+1;k<=x;k++){
				if(a[q[k]]=k)a[q[k]]=0;
				q[k]=0;
			}
			x=a[s[j]]+1;
			q[x-1]=s[j];
		}
	}
	for(int j=i;j<=n;j++){
		a[j]=0;
		q[j]=0;
	}
	return a[w]>0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	long long ans=0;
	for(long long j=1;j<=m;j++){
		for(long long i=1;i<=n;i++){
			if(qwer(i,j))ans++;
		}
		cout<<ans<<' ';
		ans=0;
	}
	return 0;
}
