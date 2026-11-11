#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
long long ans[300005],pin[300005];

//ceshidian7~9&20&1~3
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int x1=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if (a[i]<a[i-1]) x1=0;
    }
    if(x1){
        int j=0;
        for(int i=1;i<=n;i++){
            if(ans[a[i]]==0){
                j++;
            }
            ans[a[i]]++;
        }
        for(int i=1;i<=m;i++){
            ans[i]=ans[i]+ans[i-1];
        }
        for(int i=1;i<=m;i++){
            cout << ans[i]<<" ";
        }

    }
    else{
        if(m==2){
            for(int i=1;i<=n;i++){
                if(!pin[a[i]]){pin[a[i]]=0;}
                pin[a[i]]++;

            }
            long long minn=min(pin[1],pin[2]);
            if(a[n]==1){
                cout << n<<" "<<minn;
            }
            else{
                cout << minn<<" "<<n;
            }
        }
        if(m==1){
            cout<<n;
        }

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}