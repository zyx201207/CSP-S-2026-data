#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;

ll n,m,a[N],ans;

bool check(int mid){
	
	bool flag=0;
	for(int i=1;i<=n-mid;i++){
		int used=0;
		for(int j=i;j<=i+mid;j++){
			used=used+(a[i+mid-1]-a[j]);
		}
		if(used<=m){
			flag=1;
			break;
		}
	}
	return flag;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    sort(a+1,a+n+1);
    
    int l=1,r=n;
    while(l<=r){
    	int mid=(l+r)/2;
    	if(check(mid)){
    		ans=mid;
    		l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
}

