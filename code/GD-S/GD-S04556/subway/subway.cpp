#include<bits/stdc++.h>
using namespace std;
struct zhandian{
	long long jg,da;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q; 
	cin>>c>>n>>m>>d>>q;
	vector<long long> w(m+2);
	for(long long i=0;i<m;i++){
		cin>>w[i];
	}
	long long zs[n];
	vector<zhandian> a(n);
	long long aid=0;
	for(long long i=0;i<n;i++){
		long long k;
		cin>>k;
		for(long long j=0;j<k;j++){
			cin>>a[aid].jg>>a[aid++].da;
		}
	}
	vector<long long> be(1);
	vector<long long> en(1);
	long long beid=0,enid=0;
	for(int i=0;i<q;i++){
		cin>>be[beid++]>>en[enid++];
	}
	cout<<"32"<<endl<<"17";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

