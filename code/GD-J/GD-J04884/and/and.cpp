#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int a[201010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans-ans^a[i];
	
	}
	cout<<ans;
	
	return 0;

} 

    
