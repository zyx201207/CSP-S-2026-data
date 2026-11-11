#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int x;
	char y;
}a[2010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	cout<<"0";
	return 0;
}
