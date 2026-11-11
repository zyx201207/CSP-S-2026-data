#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,a[N],ma=0,x=0;
void f(int s,int num,int t){
	if(t==0){
		ma=max(ma,num);
		return;
	}
	for(int i=s+1;i<=n;i++){
		f(i,num&a[i],t-1);
		if(ma==x) return;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=max(x,a[i]);
	} 
	for(int i=1;i<=n;i++){
		f(i,a[i],m);
		if(ma==x) break;
	}
	cout<<ma;
	return 0;
} 
