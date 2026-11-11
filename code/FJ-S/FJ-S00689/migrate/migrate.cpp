#include<bits/stdc++.h>
using namespace std;
long long c,t,x[2000005],a[2000005]={0};

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		long long n,d,cnt=0;
		cin>>n>>d;
		d=2*d-1;
		for(long long j=1;j<=n;j++){
			cin>>x[j];
			a[x[j]]=1;
		} 
		for(long long j=1;j<n;j++){
			if(a[x[j]+d]==1&&x[j+1]!=x[j]+d){
				cnt++;
			}
		}
		cout<<cnt<<endl;
		for(long long j=1;j<=n;j++){
			a[x[j]]=0;
		} 
	}
 	return 0;
 }
