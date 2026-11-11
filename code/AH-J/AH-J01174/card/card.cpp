#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000100],dm;
struct t{
    int c,s;
}b[5000100];
void qink_(int dd){
    for(int i=dd;i<=dm;i++){
        b[i].s=0;
    }
}
int main(){
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int z=1;z<=n;z++){
                if(b[z].s==a[j]){
                    qink_(z);
                    break;
                }

            }b[j].s=a[j];
        }
        for(int j=1;j<=n;j++){
            if(b[j].s!=0){
                b[j].c++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<b[i].c<<' ';
    }
    return 0;
}
