#include<bits/stdc++.h>
using namespace std;
int n,m,ans,promax=-1;
int a[100005];
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("andin","r",stdin);
	freopen("andout","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	promax=a[m];
	cout<<promax;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
