#include<bits/stdc++.h>
using namespace std;
char a[10010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int m;
	for(int i=1;i<=n;i++){
		cin>>m>>a[i];
	}
	if(n<=2){
			cout<<"0";
	}
}
