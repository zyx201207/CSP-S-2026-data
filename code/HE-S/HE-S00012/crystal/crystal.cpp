#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	int m;
	int zshu;
	int yshu;
	int zhongshu;
	int aws=0;
	cin>>n>>m;
	if(n%2==0){zhongshu=n/2;}
	if(n%2==1){zhongshu=(n+1)/2;}
	for(int i=0;i<n;i++){
		cin>>a[i];
		sort(a,a+n);}
		cout<<zhongshu<<endl;

	}	
