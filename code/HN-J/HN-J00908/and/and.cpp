#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	ans=a[0];
	for(int i=0;i<m;i++)
		ans=ans&a[i];
	cout<<ans;
	return 0;
}
