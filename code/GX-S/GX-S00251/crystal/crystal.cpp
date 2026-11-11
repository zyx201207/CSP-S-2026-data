#include<bits/stdc++.h>
using namespace std;
const int MAXn = 5e5+10;
long long m;
int n , a[MAXn];
int c[MAXn],sum[MAXn];
int ans = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i = 1 ; i <= n ; i++){
		printf("%d ",a[i]);
	}
    cout<<'\n';
    for(int i = 1 ; i <= n ; i++){
        c[i] = a[i]-a[i-1];
    }
    for(int i = 1 ; i <= n ; i++){
        sum[i] = c[i] + sum[i-1];
    }
    for(int i = n ; i >= 1 ; i--){
        if(sum[i] <= m){
            ans = n - i + 1;
            break;
        }
    }
    cout<<ans;

    return 0;
}

