//GZ-J00587 六盘水市第二十四中学 许浩然 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxi;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int s;
		cin>>s;
		maxi=max(maxi,s);
	}
	cout<<maxi;
	return 0;
}
