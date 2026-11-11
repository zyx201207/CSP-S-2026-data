#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans,cnt,xm,d,c;
vector<ll> a(500000);
bool fb=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==1) d=a[i]-a[i-1];
		if(i>2&&a[i]-a[i-1]!=d) fb=0;
	}
	if(fb){
		cnt=1;
		c=m/d;
		for(int i=1;i<n;i++){
			if(c>i){
				c-=i;
				cnt++;	
			}else{
				break;
			}
		}
		cout<<cnt;
	}else{
		sort(a.begin(),a.begin()+n);
		for(int i=1;i<n;i++){
			xm=m;
			cnt=1;
			for(int j=i-1;j>=0;j--){
				if(xm>=a[i]-a[j]){
					xm-=a[i]-a[j];
					cnt++;		
					if(xm==0) break;
				}
			}
		if(cnt>ans) ans=cnt;
	}
	cout<<ans;
	}
	
	return 0;
} 
