//GZ-J00080  贵阳市云岩区中天中学  熊昱皓 
#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,k;
	cin>>n>>m;
	vector<long long>a(n),ans(m+1,0);
	for(long long i=0;i<n;i++){
		cin>>a[i];
		ans[a[i]]=i+1;
	}
	for(long long i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
