#include<bits/stdc++.h>
using namespace std;
long long n,m,cs=0,a[200005];bool b[200005];
long long dfs(int i,int j){
    //cout<<1;
    if(i==m){
            if(b[j]==1){
                return 0;
            }
        //cout<<"/\\"<<' '<<a[j]<<"/\\";
        return a[j];

    }
    if(i==0){
            long long maxx=0;
        for(int k=1;k<=n;k++){
            if(b[k]==1){//cout<<2<<' ';

                    continue;

            }b[k]=1;
        cs++;
        if(cs>=1000000000){
                //cout<<3;
            return maxx;

        }
        long long x= dfs(i+1,k);b[k]=0;
        if((x)>maxx){//cout<<4<<' ';
                //cout<<a[j]<<' '<<x<<"|";
            maxx=max(maxx,(x));
        }


    }
    //cout<<'/'<<maxx<<'\n';
    return maxx;

    }
    long long maxx=0;
    for(int k=1;k<=n;k++){
            if(b[k]==1) {//cout<<2<<' ';
            continue;

            }
        cs++;
        if(cs>=1000000000){
                //cout<<3;
            return maxx;

        }b[j]=1;
        long long x=dfs(i+1,k);
        if((a[j]&x)>maxx){
                //cout<<3<<' ';
                //cout<<a[j]<<' '<<x<<"|";
            maxx=max(maxx,(a[j]&x));
        }

        b[j]=0;
    }
    //cout<<'\\'<<maxx<<'\n';
    return maxx;


}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //cout<<n;
    cout<<dfs(0,0);
    return 0;
}
