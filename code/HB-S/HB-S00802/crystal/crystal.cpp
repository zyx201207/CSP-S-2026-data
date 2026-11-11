#include<bits/stdc++.h>
using namespace std;
long long n,m,tmm,a[50005],mx=-1e9,l=1,b[50005];//gun dong pan ding , zhao chu zui duo de bu fen
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long mmm=-1e9;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //cout<<i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        tmm=m;
        mx=-1e9;
        for(int j=l;j<=i;j++){
            mx=max(a[j],mx);
        }
        for(int j=l;j<=i;j++){
            tmm-=(mx-a[j]);
            //cerr<<"mx="<<mx<<"a[j] "<<a[j]<<"jianshaodezhi "<<mx-a[j]<<"dangqian"<<tmm<<"\t";
            while(tmm<0){
                tmm+=(mx-a[l]);
                l++;
                //cout<<l<<" ";
                //cerr<<888;
            }
        }
        //cerr<<endl;
        //cerr<<tmm<<" ";

        mmm=max(mmm,(i-l));

    }

    cout<<mmm+1;
    return 0;
}
//sqrt
        //b[i]=tmm;
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7

//10 5 3 2 1 3 3 3 3 3 3 3
