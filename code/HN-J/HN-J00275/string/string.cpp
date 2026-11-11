#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int len;
	char id;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].len>>a[i].id; 
	int l=1,r=n,ans=0;
	while(l!=r){
		if(a[l].len<a[r].len){
			if(a[r].id!=a[l].id)ans+=a[l].len;
			a[r].len-=a[l].len; 
			l++;
		}
		else{
			if(a[l].id!=a[r].id)ans+=a[r].len;
			a[l].len-=a[r].len; 
			r--;
		}
	}
	cout<<ans;
	return 0;
}
