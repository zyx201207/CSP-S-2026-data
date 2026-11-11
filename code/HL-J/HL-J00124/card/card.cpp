#include <bits/stdc++.h>
using namespace std;
long long cnt[300010],a[300010],s[300010];
//stack <int>s[300010];
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    bool b=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i]!=a[i-1])b=1;
    }
    if(b==1){
        for(int i=1;i<=n;i++){
        cout<<1<<" ";
    }
    }
    /*for(int i=1;i<=n;i++){
        if(i==1){
            cnt[a[i]]++;
        }
        else{
            if(cnt[a[i]==0){
                cnt[a[i]]++;

            }
        }

    }*/
    return 0;
}

