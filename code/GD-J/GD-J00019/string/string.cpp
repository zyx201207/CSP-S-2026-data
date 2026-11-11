#include<bits/stdc++.h>
using namespace std;
int n,cnt; 
struct m{
	int x;
	char y;
}a[100005];
int main(){
	freopen("string,in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
	}
	if(n=1) cout<<0;
	else cout<<a[1].x;
	return 0;
}
