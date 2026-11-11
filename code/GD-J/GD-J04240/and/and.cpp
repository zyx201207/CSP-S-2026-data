#include<bits/stdc++.h>
using namespace std;
int n,m,ma,x,mj;
vector<int>q;
int a[1000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=m;i++){
		q.push_back(i);
	}mj=a[1];
	for(int i=1;i<=m;i++){
		mj=mj and a[i];
	}cout<<mj;
	return 0;
}
