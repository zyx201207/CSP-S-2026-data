#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2114514];
int qian[2114514],hou[2114514],l[2114514],r[2114514];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            qian[i]=hou[i]=l[i]=r[i]=0;
        }
        l[1]=1,r[n]=n;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[i]-a[j]>d||j==0){
                    l[i]=j+1;
                    break;
                }
            }
            for(int j=i+1;j<=n+1;j++){
                if(a[j]-a[i]>d||j==n+1){
                    r[i]=j-1;
                    break;
                }
            }
        }
        for(int i=n;i>=2;i--){
            if(a[i]-a[i-1]<=d&&(i==2||a[i]-a[i-2]>d)) qian[i]=qian[i+1]+1;
            else qian[i]=0;
        }
        for(int i=1;i<n;i++){
            if(a[i+1]-a[i]<=d&&(i==n-1||a[i+2]-a[i]>d)) hou[i]=hou[i-1]+1;
            else hou[i]=0;
        }
    /*   for(int i=1;i<=n;i++) cout<<qian[i]<<" ";cout<<"\n";
        for(int i=1;i<=n;i++) cout<<hou[i]<<" ";cout<<"\n";
        for(int i=1;i<=n;i++) cout<<l[i]<<" ";cout<<"\n";
        for(int i=1;i<=n;i++) cout<<r[i]<<" ";cout<<"\n";*/
        int ans=0;
        for(int i=2;i+1<n;i++){
            if(r[l[i+1]]==i+1&&l[r[i]]==i&&l[i+1]!=i&&r[i]!=i+1){
                int ansl=0,ansr=0;
                for(int ii=l[i+1];ii<l[i+2];ii++){
                    int las=ii,las2=i;
                    ansl++;
                    for(int id=ii;id>=1;id--){
                        if(l[id]!=id-1) break;
                        if(r[l[id]]!=id) break;
                        ansl++;
                    }
                }
                for(int jj=r[i-1]+1;jj<=r[i];jj++){
                    int las=jj,las2=i+1;
                    ansr++;
                    for(int jd=jj;jd<=n;jd++){
                        if(r[jd]!=jd+1) break;
                        if(l[r[jd]]!=jd) break;
                        ansr++;
                    }
                }

                ans+=ansl*ansr;
        //       cout<<i<<":"<<ansl<<" "<<ansr<<"   "<<r[i]-i-1<<" "<<i-l[i+1]<<"\n";
            } 
        }
        cout<<ans<<"\n";
    }

}
/*
g++ migrate.cpp -o migrate

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
daan:6

0 1
6 4
-3 0 1 2 3 4
daan:3

0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
daan:9
*/