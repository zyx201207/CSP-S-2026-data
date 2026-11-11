#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500050;
int a[N],t[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){	
        cin>>a[i];
        t[i]=a[i];
    }    
    //cout<<"TTT";
    sort(a+1,a+n+1);
    sort(t+1,t+n+1);
    for(int i=1;i<=n;i++){
       a[i]+=a[i-1];
      // cout<<t[i]<<' ';
	}
	//cout<<'\n';
    int ans=1;
    for(int i=1,j=1;j<=n&&i<=n;j++){
        while(t[i]*(i-j+1)-(a[i]-a[j-1])<=m&&i<=n) i++;//i
        if(ans<i-j){
			ans=i-j;
		//	cout<<i<<' '<<j<<'\n';
			//cout<<"aaa"<<t[i-1]*(i-j)<<' '<<a[i]-a[j-1]<<'\n';
		}
    }
  
    cout<<ans;
    return 0;
}

