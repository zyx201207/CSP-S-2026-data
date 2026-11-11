#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005],b[1000005];
long long c[1000005]={0},max1,maxx;
int qp(int t){
	if(t==m){
		maxx=0;
		for(long long i=0;i<m;i++){
			if(maxx==0)maxx=b[i];
			else maxx&=b[i];
		}
		max1=max(max1,maxx);
		return 0;
	}
	for(long long i=0;i<n;i++){
		if(c[i]!=1){
			b[t]=a[i];
			c[i]=1;
			qp(t+1);
			c[i]=0;
			b[t]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	qp(0);
	cout<<max1;
	return 0;
} 
