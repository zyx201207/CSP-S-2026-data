#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[n*m]={0},b[N]={0};
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    if(m==1){
        int maxx=-999;
        for(int i=1;i<=n;i++){
            if(b[i]>=maxx){
                maxx=b[i];
            }
        }
        cout<<maxx;
        return 0;
    }
    if(m==2){
        int num=1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                a[num]=b[i]&&b[j];
                num++;
            }
        }
        int maxx=0;
        for(int i=1;i<=num;i++){
            if(a[i]>=maxx){
                maxx==a[i];
            }
        }
        cout<<maxx;
        return 0;
    }




    fclose(stdin);
    fclose(stdout);
    return 0;
}




