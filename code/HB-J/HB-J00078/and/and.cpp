#include<bits/stdc++.h>
using namespace std;
int f[200010],a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    f[0] = 2147483647;
    for(int i = 1;i <= n;i++){
    	for(int j = min(m,i) ;j >= 1;j--){
    	    f[j] = max(f[j],(f[j - 1] & a[i]));
    	}
    }
    cout<<f[m]<<"\n";
    return 0;
}
