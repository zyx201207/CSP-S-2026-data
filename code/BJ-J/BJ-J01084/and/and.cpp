#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxn = -1e5;
    int stop1 = -99,stop2 = -11;
    for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i==j)continue;
                int con = a[i]&a[j];
                if(con>maxn){maxn = con;stop1=i;stop2=j;}
            }
        }
    //cout<<stop1<<" "<<stop2<<endl;
    a[stop1] = -1;a[stop2] = -1;
    for(int k=0;k<m-2;k++){
        int ze = maxn;
        int stop3;
        maxn = -10086;
        for(int i=0;i<n;i++){
            if(a[i]==-1)continue;
            int con = a[i]&ze;
            if(con>maxn){maxn = con;stop3=i;}
        }
        a[stop3]=-1;
    }
    cout<<maxn;
    return 0;
}
