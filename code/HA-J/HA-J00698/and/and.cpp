#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ejzwy=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	ejzwy=a[1];
	for(int i=2;i<=m;i++){
		ejzwy=(ejzwy&a[i]);
	}
	cout<<ejzwy;
	return 0;
}
