#include<bits/stdc++.h>
using namespace std;
struct node{
	int n,d;
	int x[10005];
}a[10005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,sum=0;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>a[i].n>>a[i].d;
		for(int j=0;j<a[i].n;j++)cin>>a[i].x[j];
	}
	for(int i=0;i<t;i++){
		cout<<sum;
		sum+=1;
	}
	return 0;
}
