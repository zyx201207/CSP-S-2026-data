#include<bits/stdc++.h>
using namespace std;
int cha[100005];
int dimond[1000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    cha[0]=0;
    for(int i=1;i<=n;i++){
        cin >> dimond[i];
    }
    sort(dimond+1,dimond+1+n);
   long long maxend=0;
     for(int i=1;i<=n;i++){
       cha[i]=dimond[i]-dimond[i-1];

    }
        for(int i=1;i<=n;i++){
                long long sum=0,suml=0,geshu=0;
            for(int j=i;(sum<=m)&&(j<=n);j++){
              // cerr << geshu << " "<<sum;
                    //cerr << "debug"<<i<<" "<<j<<endl;
                   // cerr << "thissum"<<geshu*cha[j]<<endl;
               sum+=geshu*cha[j];
              // cerr<<sum<<" "<<m<<endl;
               if(sum<=m){
                geshu++;
               }
            }
            maxend=max(maxend,geshu);
        //cerr << endl;
        }
        cout << maxend;
    return 0;
}
