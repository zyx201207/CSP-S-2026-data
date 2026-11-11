#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans,n;
struct node{
	int a;
	char c;
};
node arr[200540];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].a>>arr[i].c;
	}
	int l=1,r=n;
	while(l<r){
		int d=min(arr[l].a,arr[r].a);
		arr[l].a-=d,arr[r].a-=d;
		if(arr[l].c!=arr[r].c) ans+=d;
		if(arr[l].a<=0) l++;
		if(arr[r].a<=0) r--;
	}
	cout<<ans; 
	return 0;
}
//Trick||Treat!
