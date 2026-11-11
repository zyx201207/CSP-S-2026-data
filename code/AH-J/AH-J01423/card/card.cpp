#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long n1[500005];
long long m1[300005];
long long bj[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>n1[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			m1[n1[j]]++;
			if(m1[n1[j]]>1){
				memset(m1,0,sizeof(m1));
				m1[n1[j]]++;
			}
		}
		for(long long j=1;j<=m;j++)if(m1[j]>0)bj[j]++;
		memset(m1,0,sizeof(m1));
	}
	for(long long i=1;i<=m;i++)cout<<bj[i]<<" ";
	return 0;
}
