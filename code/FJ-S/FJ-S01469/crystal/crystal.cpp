#include<bits/stdc++.h>
using namespace std;
int n,cnt,t,mx;
long long m,mn=1000000001;
long long a[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){    
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int cnt=1,t=0;
	}
	for(int j=2;j<=n;j++){
		if(a[j]-a[j-1]*t<=m){
			cnt++;
		m-=(a[j]-a[j-1])*t;
		}
		mx=max(mx,cnt);
		if(m<=0)
		break;
		t++;
	}
	cout<<mx;
	return 0;
} 
