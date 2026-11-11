#include<iostream>
#include<vector>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int n;
long long d;
int find(vector<long long>h,long long s,long long e){
	int cnt=0;
	vector<int> r;
	r.push_back(1);
	for(long long i=0;i<e-s+1;i++){
		for(long long j=i;j>=i-d;j++){
			r[i]+=r[j];
		}
	}
	return r[e];
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int ans=0;
		vector<long long> a;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			long long c;
			cin>>c;
			a.push_back(c);
		}
		for(long long i=0;i<n-1;i++){
			for(long long j=1;j<n;j++){
				if(find(a,i,j)==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
