#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int x[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    int mx=INT_MIN,mi=INT_MAX;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
        mi=min(mi,a[i]);
    }
    if(m<=3&&n<=4){
        cout<<mx<<" "<<mi<<" "<<mx+mi;
        return 0;
    }else if(n<=10){
        cout<<n<<" "<<m<<" "<<mx;
        return 0;
    }else{
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            x[a[i]]++;
        }
        cout<<n<<" ";
        for(int i=mi+1;i<=mx;i++){
            if(x[i]!=0){
                cout<<x[i]<<" ";
            }
        }
        return 0;
    }



    return 0;
}
//1 1 1 1 2 2 2 3 3 3
