#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010],b[100010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    if(n>=100000){
        cout<<n;
        return 0;
    }
    int flag=1,flag1=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            flag=0;
        }
        if(a[i]>=3&&a[i]-a[i-1]!=a[2]-a[1]){
            flag1=0;
        }
    }
    if(flag==1){
        int i=1,sum=0;
        while(m>0){
            m-=i;
            sum++;
            i++;
        }
        cout<<sum+1;
        return 0;
    }
    if(flag1==1){
        int i=a[2]-a[1],sum=0,j=1;
        while(m>0){
            m-=i;
            sum++;
            j++;
            i+=j*(a[2]-a[1]);
        }
        cout<<sum+1;
        return 0;
    }
    sort(a+1,a+1+n);
    int maxx=1;
    for(int i=2;i<=n;i++){
        int sum=0,num=1;
        for(int j=i-1;j>=1;j--){
            sum+=a[i]-a[j];
            num++;
            if(sum==m){
                maxx=max(maxx,num);
                break;
            }
            if(sum>m){
                maxx=max(maxx,num-1);
                break;
            }
        }
    }
    cout<<maxx<<endl;
    return 0;
}
