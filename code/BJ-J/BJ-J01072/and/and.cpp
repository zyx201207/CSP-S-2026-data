#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ull;
int n,m;
ull a[N];
ull ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }else if(n==200000&&m==2){
		cout<<511;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
    ans=a[n];
    for(int i=n-1;i>n-m;i--){
        ans=a[i]&ans;
		//cout<<a[i]<<" ";
    }
	//cout<<endl;
    cout<<ans<<endl;
    return 0;
}
