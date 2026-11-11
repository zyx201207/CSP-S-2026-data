#include <bits/stdc++.h>
using namespace std;
int n,m,num;
int a[200005];
void d(int M,int maxxx,int p){
	if(M==0){
		num=max(maxxx,num);
		return;
	}
	if(p+M>n+1) return;
	if(M==m){
		d(M-1,a[p],p+1);
	}
	else{
		d(M-1,(a[p]&maxxx),p+1);
	}
	d(M,maxxx,p+1);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	d(m,0,1);
	cout<<num<<" ";
	return 0;
} 
