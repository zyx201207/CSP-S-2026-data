#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500001],m,sum[500002];
int main(){
//    freopen("D:\\crystal\\crystal4.in","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin>>n>>m;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int med=0;
    for(int i=1;i<=n;i++){
        if((a[i])*i-sum[i]<=m){
            continue;
        }else{
            med=i-1;
            break;
        }
    }
    cout<<med<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
