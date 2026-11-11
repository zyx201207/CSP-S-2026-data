#include <bits/stdc++.h>
using namespace std;
vector<long long> v(1,0);
int cnt,m,n;
long long maxn,andn,temp;
void maxand(int st){
	if(cnt==(m-1)){
		if(maxn<andn){
			maxn=andn;
			andn=temp;
		}
		cnt=0;
		return;
	}
	for(int i=st+1;i<=n&&st!=n;i++){
		temp=andn;
		andn=v[st]&v[i];
		cnt++;
		maxand(st+1);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		v.push_back(a);
	}
	for(int j=1;j<n;j++){
		maxand(j);
	}
	cout<<maxn;
	return 0;
}
