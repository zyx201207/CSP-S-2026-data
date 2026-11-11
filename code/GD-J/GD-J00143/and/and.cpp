#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long ans;
void f(int x,int d,long long num){
	if(d==m){
		ans=max(ans,num);
		return;
	}
	for(int i=x+1;i<=n;i++){
		f(i,d+1,(num&a[i]));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	} 
	for(int i=1;i<=n;i++){
		f(i,1,a[i]);
	} 
	cout<<ans;
	return 0;
} 
