#include<bits/stdc++.h>
using  namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int n,m;
	cin>>n>>m;
	long long a[200001]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int ans=a[0];
	 for(int i=1;i<m;i++){
	 	ans&=a[i];
	 }
	 cout<<ans<<endl;
	 freopen("and.in","r",stdin);
	 freopen("and.out","w",stdout); 
	return 0;
}
