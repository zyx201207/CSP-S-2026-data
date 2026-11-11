#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int d[m];
	int y=0;
	for(int i=m;i>0;i--){
		d[y]=a[i];
		y++;
	}
	cout<<d[m-1] and d[m];
	return 0;
} 
