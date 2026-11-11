#include<bits/stdc++.h>
using namespace std;
int a[555];
int cnt[333];
int n,m;
int t[555];
int p;
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){

            for(int i=1;i<=p;i++){
                t[i]=0;
            }
                p=1;
        for(int j=i;j<=n;j++){
            bool flag=true;
            int poin=a[j];
            for(int i=1;i<=p;i++){
                if(t[i]==poin){
                    flag=false;

                }
            }
            if(flag){
                t[p++]=poin;
            }else {
                while(1){
                    p--;
                    if(a[p]==poin){
                        break;
                    }

                }
                p++;

            }


        }

        for(int i=1;i<=p;i++){
            cnt[t[i]]++;
        }

    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
