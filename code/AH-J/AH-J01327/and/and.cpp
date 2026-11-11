#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
typedef long long ll;
int n,m,a[N],mx=-1,he=1,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>mx){
			mx=a[i];
		}
		he=he&a[i];
	}
	if(m==1){
		cout<<mx;
	}else if(m==n){
		cout<<he;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
    return 0;
}


