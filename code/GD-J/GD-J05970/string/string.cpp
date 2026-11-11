#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int z;
	char c;
}a[200005];
int n,cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].z>>a[i].c;
	}
	int ans=0,l=1,r=n;
	while(l<r){
		if(a[l].z<a[r].z){
			a[r].z-=a[l].z;
			if(a[l].c!=a[r].c)
			ans+=a[l].z;
			l++;
		}else if(a[l].z>a[r].z){
			a[l].z-=a[r].z;
			if(a[l].c!=a[r].c)
			ans+=a[r].z;
			r--;
		}else{
			if(a[l].c!=a[r].c)
			ans+=a[r].z;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
