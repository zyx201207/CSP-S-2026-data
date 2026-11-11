//GZ-J00080  贵阳市云岩区中天中学  熊昱皓 
#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	vector<long long>a(n);
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	cout<<a[n-m];
	return 0;
}
