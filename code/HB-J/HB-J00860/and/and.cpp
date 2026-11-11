#include<bits/stdc++.h>
using namespace std;
struct node{
    long long num;
    int ox[10005];
}a[50000];
long long n,m;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        int t=1,nu=a[i].num;
        while(nu>0){
            if(nu==1){
                a[i].ox[t]=1;
                nu=0;
            }
            else{
                if(nu%2==1){
                    a[i].ox[t]=1;
                    nu/=2;
                    t++;
                }
                else{
                    a[i].ox[t]=0;
                    nu/=2;
                    t++;
                }
            }
        }
    }

    return 0;
}
