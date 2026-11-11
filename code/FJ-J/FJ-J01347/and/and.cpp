#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],x=12,y=15;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	long long ans=a[0];
	//cout<<a[0];
	for(int i=1;i<m;i++){
		//cout<<a[i]<<" "<<ans<<endl; 
		ans=ans&a[i];
	} 
	cout<<ans;
	return 0; 
}
