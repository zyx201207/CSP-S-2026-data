#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,m;
bool cmp(long long x,long long y){
	if(x%2==1&&y%2==0)return x%2==1&&y%2==0;
	else return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	//for(int i=1;i<=n;i++){
	//	cout<<a[i]<<' ';
	//}
	
	int ans=a[1];
	for(int i=1;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	
	return 0;

} 
