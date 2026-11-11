#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll arr[int(5e5)];
int main(){
	freopen("crystal.in" ,"r", stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n,m,s=0,cnt=0,tmp,mn=1e9;cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		cnt+=arr[i];
	}sort(arr,arr+n);
	cnt/=n;
	for(ll i=0;i<n;i++){
		if(abs(arr[i]-cnt)<=mn) mn=abs(arr[i]-cnt);
		else{
			cnt=arr[i],tmp=i;break;
		}
	}
	for(ll i=tmp-1;i>=0&&m>0;i--){
		int temp=cnt-arr[i];
		if(m-temp>=0&&cnt-arr[i]>=0)
			m-=temp,arr[i]=cnt;
	}
	for(ll i=0;i<n;i++)
		if(arr[i]==cnt) s++;
	cout<<s;
	return 0;
}