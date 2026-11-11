#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,m,d,q;
struct way{
	int idx;
	long long ti;
};
void sub(){
	cin>>n>>m>>d>>q;
	vector<long long>w(m+1);
	vector<long long>k(n+1);
	vector<way>t(n);
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
	}
}
int main(){
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	cout<<ans;
	return 0;
}
