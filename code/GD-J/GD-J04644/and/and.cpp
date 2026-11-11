#include<bits/stdc++.h>
using namespace std;
int n,m,s=0;
struct node{
	int an,x,y;
}a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].y=1;
		a[i].an=0;
		for(int j=1;j<i;j++){
			a[i].an=max(a[i].an,a[j].an&a[i].x);
			s=max(a[i].an,s);
		}
	}
	cout<<s;
	return 0;
}
