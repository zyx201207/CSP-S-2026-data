#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int ans;
    for(int i=1;i<=m;i++){
        sort(a+1,a+n+1);
        int min=1e9;
        int t;
        for(int i=n;i>=2;i--){
            if(a[i]-a[i-1] < min){
                min=a[i]-a[i-1];
                t=i-1;
            }
        }
        a[t]&=a[t+1];
        a[t+1]=0;
        ans=a[t];
    }
    cout<<ans;
	return 0;
}

