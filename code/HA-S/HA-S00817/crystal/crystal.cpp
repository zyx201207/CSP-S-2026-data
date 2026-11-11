#include<bits/stdc++.h>
using namespace std;
long long cnt,ans=1,n,m,a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n==0){
		cout<<0;
		return 0;
	}else if(n==1){
		cout<<1;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		b[i]=a[i+1]-a[i];
		if(i == n){
			b[i]=a[i];
		}
    }
    for(int i = 1;i <= n;i++){
	    if(b[i]!=0&&cnt>=m){
	    		cout<<ans;
			    return 0;	
	    }
		cnt+=b[i]*i;
	    ans++;
    }
}
