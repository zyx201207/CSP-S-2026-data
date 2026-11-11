#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	
	//我常常追忆过去
	//前面忘了
	//中间忘了
	//我应该在哪里停留？我问我自己
	
	return 0;
}