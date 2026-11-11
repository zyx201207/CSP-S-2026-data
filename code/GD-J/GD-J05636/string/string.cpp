#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct node{
	long long cnt;
	char c;
}arr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i].cnt >>arr[i].c ;
	int l=1,r=n;
	while(l<r){
		if(arr[l].cnt ==arr[r].cnt ){
			if(arr[l].c !=arr[r].c )ans+=arr[l].cnt ;
			l++,r--;
		}
		else if(arr[l].cnt >arr[r].cnt ){
			if(arr[l].c !=arr[r].c )ans+=arr[r].cnt ;
			arr[l].cnt -=arr[r].cnt ;
			r--;
		}
		else {
			if(arr[l].c !=arr[r].c )ans+=arr[l].cnt ;
			arr[r].cnt -=arr[l].cnt ;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
