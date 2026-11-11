#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+7;
long long n,m,ans=0;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	int mx=0,l=0,o;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			if(l>=mx){
				mx=l;
				o=i-l+1;
				l=0;
			}
		}
		else l++;
		//cout<<l<<" "<<mx<<endl;
	}
	int cnt=0;
	if(mx>1){
		//cout<<mx<<" "<<o<<endl;
		cnt=mx;
		for(int i=o-1;i>=1;i--){
			if(m>=a[o]-a[i]){
				m-=a[o]-a[i];
				cnt++;
			}
			//cout<<a[o]<<" "<<a[i]<<" "<<m<<" "<<cnt<<endl;
		}
	}
	int mid=(n+1)/2;
	while(a[mid+1]==a[mid]) mid++;
	int ans=1;
	for(int i=mid-1;i>=1;i--){
		if(m>=a[mid]-a[i]){
			m-=a[mid]-a[i];
			ans++;
		}
	}
	cout<<max(cnt,ans);
	return 0;
} 
