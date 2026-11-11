#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct node{
	ll num;
	char c;
}arr[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>arr[i].num>>arr[i].c;
	}
	ll l=1,r=n,ans=0;
	while(l<r){
		if(arr[l].c!=arr[r].c){
			if(arr[l].num<arr[r].num){
				ans+=arr[l].num;
				arr[r].num-=arr[l].num;
				l++;
			}
			else{
				ans+=arr[r].num;
				arr[l].num-=arr[r].num;
				r--;
			}
		}
		else{
			if(arr[l].num<arr[r].num){
				arr[r].num-=arr[l].num;
				l++;
			}
			else{
				arr[l].num-=arr[r].num;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
