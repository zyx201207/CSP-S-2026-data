#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	long long zsj=0;
	for(long long i=0;i<n;i++){
		long long x=a[i];
		long long sum=0;
		long long sj=0;
		for(long long j=0;j<n;j++){
			if(x>=a[j])
				if(sum<=m){
					sum+=x-a[j];
					sj+=1;
				}
		}
		if(zsj<sj)
			zsj=sj;
	}
	cout<<zsj;
	return 0;
}
