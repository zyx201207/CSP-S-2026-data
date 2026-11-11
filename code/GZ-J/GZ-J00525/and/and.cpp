//GZ-J00525 兴义市弘毅中学 龙乙夫
#include<bits/stdc++.h>
using namespace std;
long long const MAXN=2*1e5+5;
long long n,m;
long long a[MAXN];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long ma=0;
	for(long long i=1;i<=(1<<n);i++){
		long long nu=0;
		vector<long long> as;
		for(long long j=0;j<n;j++){
			if(i&(1<<j)){
				nu++;
				as.push_back(a[j]);
			}
		}
		if(nu==m){
			long long an=as[0];
			for(long long j:as){
				an&=j;
			}
			if(an>=ma)ma=an;
		}
	}
	cout<<ma<<endl;
	return 0;
} 
