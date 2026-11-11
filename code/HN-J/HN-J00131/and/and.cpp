#include<bits/stdc++.h>
using namespace std;
int n[1005][1005],m,l;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>l;
	for(int i=1;i>=m;i++){
		for(int j=1;j>=l;j++){
			cin>>n[i][j];
		}
	}
	cout<<n;
	
	return 0;
}
