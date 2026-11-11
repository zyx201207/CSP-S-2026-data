#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],mx;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	mx=a[0];
	for(int i=1;i<m;i++) mx=mx&a[i]; 
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}