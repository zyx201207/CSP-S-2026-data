#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans,cnt;
long long b[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>ans){
				ans=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>ans){
					ans=(a[i]&a[j]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[a[i]]++;
		if(a[i]>cnt){
			cnt=a[i];
		}
	}
	for(int i=cnt;i>=0;i--){
		if(b[i]>=m){
			ans=i;
			break;
		}
	}
	cout<<ans;
    return 0;
}
/*
4 2
3 15 12 12
*/