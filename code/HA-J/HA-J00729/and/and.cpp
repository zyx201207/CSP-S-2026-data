#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	if(x!=y){
		return x<y;
	}
}
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2+1;i++){
		b=i;
	}
	cout<<a[b];
	return 0;
}
