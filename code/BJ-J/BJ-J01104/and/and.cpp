#include<bits/stdc++.h>
using namespace std;
int n,m,maxx;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	maxx=a[1];
	for(int i=2;i<=m;i++){
		if(i>n){
			cout<<0;
			return 0;
		}
		maxx=maxx&a[i];
		if(maxx==0){
			maxx=a[i];
			m++;
		}
	 }
	cout<<maxx;
	return 0;
}
