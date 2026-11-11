#include<bits/stdc++.h>
using namespace std;
struct pai{
	int w,g,z;
}p[500005];
int n,m,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i].z;
		p[i].g++;
	}
	for(int i=1;i<=m;i++){
		if(p[i].z==p[i+1].z)	cout<<1;
		else	cout<<n+1-i<<" ";
	}	
	
	

	
	return 0;
}
