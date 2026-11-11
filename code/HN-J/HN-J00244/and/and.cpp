#include<bits/stdc++.h>
using namespace std;
int a[10000005],b[10000005];
int f(int n,int m,int maxn){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]&a[j]>maxn)
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	m--;
	if(m>0)f(n,m-1,maxn);
	else return maxn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<f(n,m-1,0);
	
	return 0;
} 
