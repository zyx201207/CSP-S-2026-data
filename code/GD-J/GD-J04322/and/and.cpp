#include<bits/stdc++.h>
using namespace std;
long long l[200001],ans;
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>l[i];
	sort(l+0,l+n,cmp);
	ans=l[0];
	for(int i=1;i<m;i++)ans&=l[i];
	cout<<ans;
	return 0;
}
