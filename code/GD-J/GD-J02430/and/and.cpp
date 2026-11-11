#include<bits/stdc++.h>
using namespace std;
int b[200001]={0};
int a[200001]={0};
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	int u=a[1];
	for(int i=2;i<=m;i++){
		u=a[i]&u;
	}
	cout<<u;
	return 0;
} /*
262142

Trick||Treat!
*/
