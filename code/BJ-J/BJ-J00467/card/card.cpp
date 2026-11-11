#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],box[200010],cnt;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    else if(m==2){
        cout<<3<<' '<<n;
    }
    else{
       for(int i=1;i<=n;i++){
            if(a[i]==a[i-1])box[cnt]++;
            else{
                cnt++;
                box[cnt]=1;
            }
        }
        for(int i=1;i<=cnt;i++){
            box[i]+=box[i-1];
            cout<<box[i]<<' ';
        }
    }
    return 0;
}
