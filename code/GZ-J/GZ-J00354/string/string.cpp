//GZ-J00354 湄潭县茶城中学 孟梓涵 
#include<bits/stdc++.h>
using namespace std;
int n,a[200002],l;
string c,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s1+=c[i];
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(s1[0]==s1[1])cout<<0;
	else cout<<1;
	return 0;
}
