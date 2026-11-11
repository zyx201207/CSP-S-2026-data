#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll a;
	string c;
}arr[1000010],brr[1000010];
ll n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>arr[i].a>>arr[i].c;
		brr[n-i+1].a=arr[i].a;
		brr[n-i+1].c=arr[i].c;
	}
	ll q=1;
	for(ll i=1;i<=n;i++){
	while(arr[i].a>0){
		if(brr[q].a<=arr[i].a){
			arr[i].a-=brr[q].a;
			if(arr[i].c!=brr[q].c)ans+=brr[q].a;
			brr[q].a=0;
			q++;
		}else{
			brr[q].a-=arr[i].a;
			if(arr[i].c!=brr[q].c)ans+=arr[q].a;
			arr[q].a=0;
		}
	}
	}
	cout<<ans/2;
	return 0;
}
