#include<bits/stdc++.h>
using namespace std;
int n,z,ans,q=1;
char x,s[1111111];
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>z;
		cin>>x;
		for(int j=q;j<=q+z;j++){
			s[j]=x;
		}
		q+=z;
	}
	int l=1,r=q;
	while(l<=r){
		if(s[l]!=s[r]){
			
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
