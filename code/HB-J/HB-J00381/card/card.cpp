#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define LL long long
LL n,m;
LL cards[N],book[N],book1[N],cf[N],d[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>cards[i];
    }
    for(LL i=1;i<=n;i++){
        memset(book,0,sizeof(book));
        memset(book1,0,sizeof(book1));
        memset(cf,0,sizeof(cf));
        for(LL j=i;j<=n;j++){
            if(book[cards[j]]){
                LL le=book[cards[j]];
                cf[le]++;cf[j]--;
                for(int k=le;k<j;k++){
                    book[cards[k]]=0;
                }
                book[cards[j]]=j;
            }else{
                book[cards[j]]=j;
            }
        }
        for(int j=i;j<=n;j++){
            book1[j]=book1[j-1]+cf[j];
            if(!book1[j])d[cards[j]]++;
        }
    }
    for(LL i=1;i<=m;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
