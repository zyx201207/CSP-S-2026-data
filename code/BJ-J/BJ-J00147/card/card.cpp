#include <bits/stdc++.h>
using namespace std;
int lp[300005];
int num[500005];
int ans[300005];
int test[500005];
void cnt(int l,int r){
    int p=1;
    memset(lp,0,sizeof(lp));
    memset(test,0,sizeof(test));
    for (int i=l;i<r;i++){
        //cout<<p;
        if (lp[num[i]]!=0){
            //cout<<num[i]<<'#';
                p--;
                //cout<<num[i]<<endl;
                for (;p>lp[num[i]];p--){
                    //cout<<test[p]<<' ';
                    ans[test[p]]--;
                    lp[test[p]]=0;
                }
        }
        else{

            test[p]=num[i];
            lp[num[i]]=p;
            ans[num[i]]+=1;

        }
        p++;

    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>num[i];
    }
    int p=0;
    for (int i=0;i<n;i++){
        cnt(i,n);
    }
    for (int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
