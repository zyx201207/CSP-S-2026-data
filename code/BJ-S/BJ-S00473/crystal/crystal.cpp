#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int crystal[500005];
    for(int i=1;i<=n;i++){
        cin>>crystal[i];
    }
    sort(crystal,crystal+n);
    int same=0,maxsame=0,samenum=0,maxsamenum=0;
    for(int i=1;i<=n;i++){
        if(crystal[i]==crystal[i+1]){
            same++;
            samenum=i;
        }
        else{
            if(same>maxsame){
                maxsame=same;
                maxsamenum=samenum;
            }
            same=0;
        }
    }
    int ans=0;
    int ii=maxsamenum;
    if(maxsame>=1){
        int ct=0;
        while(m>0){
            ans++;
            ct++;
            if(crystal[ii]!=crystal[ii-1]){
                m-=crystal[ii]-crystal[ii-1]*ct;           //-3 -1 2 2 7(maxsame 1 ii 3)
            }
            ii--;
        }
        ans++;
    }
    else{
        int ct=0;
        while(m>0){
            ct++;
            ans+=ct;
            m-=(crystal[ct+1]-crystal[ct])*ct;          //1 2 4 8 9
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
