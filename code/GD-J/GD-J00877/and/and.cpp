#include<bits/stdc++.h>
using namespace std;
const int N=20000000;
long long n,m,a[N]={},sum=0,ma=0;
void dfs(int s,int last,int c){
	if(c>m){
		if(ma<sum){
			ma=sum;
		}
		return ;
	}
	for(int i=s;i<=n;i++){
		if(sum==0){
			sum=a[i];
		}
		else{
			sum=sum&a[i];
		}
		dfs(i+1,sum,c+1);
		sum=last;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,1);
	cout<<ma;
	return 0;
}
