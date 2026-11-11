#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long cnt(long long in){
	long long ans=0;
	while(in!=0){
		ans+=in%2;
		in/=2;
	}
	return ans;
}
bool cmp(long long a,long long b){
	long long at=cnt(a),bt=cnt(b);
	if(at!=bt)return at>bt;
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	long long n,m,ans=0;
	std::cin>>n>>m;
	for(long long i=0;i<n;i++)std::cin>>a[i];
	std::sort(a,a+n,cmp);
	ans=a[0];
	for(long long i=1;i<m;i++)ans=ans&a[i];
	std::cout<<ans;
	return 0;
}
