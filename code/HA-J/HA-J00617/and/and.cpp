#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
//vector< vector<int> > f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=1;i<=k;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
