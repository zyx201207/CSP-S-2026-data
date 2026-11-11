#include<bits/stdc++.h>
using namespace std;
int n,a[12122],m,s,b[10002]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s=max(s,a[i]&a[j]);
			b[a[i]&a[j]]++;
		}
	}
	for(int i=1;i<=10000;i++)if(b[i]==m) s=max(i,s);
	cout<<s;
	return 0;
} 
