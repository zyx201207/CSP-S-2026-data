#include<iostream>
#include<cstring>
using namespace std;

int n,m,now=0;

int a[500005],cards[300005],appear[300005],cnt[300005];

int find(int x){
    for(int i=1;i<=now;i++){
        if(x==cards[i])return i;
    }
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(appear,0,sizeof(appear));
        memset(cards,0,sizeof(cards));
        now=0;
        for(int j=i;j<=n;j++){
            if(!appear[a[j]]){
                now++;
                cards[now]=a[j];
                appear[a[j]]++;
            }else{
                int x=find(a[j]);
                cout<<j<<' '<<x<<endl;
                for(int k=x+1;k<=now;k++){
                    appear[cards[k]]--;
                }
                now=x;
            }
        }
        for(int j=1;j<=now;j++){
            cnt[cards[j]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
