#include<bits/stdc++.h>
using namespace std; 
int n,cnt=0,aa=0,c=1;
 
int main(){
	
	cin.tie(nullptr); 
	ios::sync_with_stdio(false);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	char a[100005];
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		aa+=x;
		for(int i=1;i<=n;i++){
			a[c]=y;
			c++;
		}
	}
	aa--; 
	for(int i=1;i<=aa/2;i++){
		if(a[i] != a[aa-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
