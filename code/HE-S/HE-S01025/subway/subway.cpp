#include <bits/stdc++.h>
using namespace std;
int t[10005][10005],m[10005][10005];
int main(){
	int m,n,d,c,q,k;
	int sub[10005];
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>sub[i];
	}
	cin>>k;
	for(int i = 1;i<=k;i++){
		cin>>t[i][1]>>t[i][2];
	}
	cout<<sub[1]+t[1][1]+(t[1][1]+t[2][2])+t[2][3]+sub[3]<<endl;
	cout<<sub[1]+t[1][1]+t[1][2]+sub[2];
	return 0;	
}
