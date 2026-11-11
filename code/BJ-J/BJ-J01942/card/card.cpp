#include<bits/stdc++.h>
using namespace std;
int cnt[300005],ans[300005],loc[300005],book[500005];bool AA=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    int A[500005];
    for(int i=0;i<n;i++){
        cin>>A[i];
        if(i>0&&A[i]<A[i-1]){
            AA=0;
        }
       // cnt[A[i]]++;
    }//ans[a[n-1]]+=1;
    if(AA){
        for(int i=1;i<=m;i++){
            cout<<i<<" ";
        }return 0;
    }
    for(int i=0;i<n;i++){
        memset(cnt,0,sizeof(cnt));
        memset(loc,0,sizeof(loc));
        memset(book,0,sizeof(book));
        for(int j=i;j<n;j++){
            if(cnt[A[j]]==0){
                cnt[A[j]]=1;
                loc[A[j]]=j;
            }else{
                for(int k=loc[A[j]];k<j;k++){
                    if(book[A[k]]==0){
                        cnt[A[k]]--;
                        book[A[k]]=-1;
                    }
                }loc[A[j]]=j;cnt[A[j]]++;
            }
        }
        for(int p=1;p<=m;p++){
            if(cnt[A[p]]){
                ans[A[p]]++;
            }
        }
    }
    for(int p=1;p<=m;p++){
        cout<<ans[p]<<" ";
    }
    return 0;
}

