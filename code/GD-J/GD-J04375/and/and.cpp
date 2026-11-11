#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int n,m,cnt=0;
ll a[N],ans=0;
void f(ll x,int y,int z){
	cnt++;
	cout <<cnt<<" "<<y<<endl;
	if(y==n||z==m){
		cout <<endl;
		ans=max(x,ans);
		return ;
	}
	for(int i=y+1;i<=n;i++){
		f(a[i]&x,i,z+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=1;i<=n;i++){
		f(a[i],i,1);
	}
	cout <<ans;
	return 0;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
