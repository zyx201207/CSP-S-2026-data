#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool cmp(int a,int b){
	return a>b;
}
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int  ans1=-1;
	for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 }
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans1=max(ans1,a[i]&a[j]);
			}
		}
		cout<<ans1;
	}else{
	 
	 sort(a+1,a+n+1,cmp);
	long long  ans=a[1];

	 for(int i=2;i<=m;i++){
	 	ans&=a[i];
	 
	 }
	 cout<<ans<<" ";
}
} 
