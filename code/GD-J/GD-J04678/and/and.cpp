#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(i==n){
			cout<<x;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
