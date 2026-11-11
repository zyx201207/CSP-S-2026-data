#include<bits/stdc++.h>
using namespace std;
int a[200005];char x[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,c;
	long long n,ans=0,sum=0;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>x[i];
	for(int y=1,z=n;y<z;){
		if(x[y]!=x[z]) ans+=min(a[y],a[z]);
		if(a[y]<a[z]){a[z]-=a[y];y++;}
		else {a[y]-=a[z];z--;}
	}cout<<ans<<"\n";
	return 0;
}
