
#include<bits/stdc++.h>
using namespace std;
int n,y,a[500005],x[500005],_29sumgpc=1;

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>y;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        _29sumgpc=1;
        int table[500005],m[500005];
        for(int j=i;j<=n;j++){

            if (m[a[j]]!=0){
                _29sumgpc=m[a[j]];
                for(int k=_29sumgpc+1;table[k]>0;k++){
                    m[table[k]]=0;
                    table[k]=0;
                    x[table[k]]--;
                }
            }table[_29sumgpc]=a[j];
            x[table[_29sumgpc]]++;
            //cout<<table[_29sumgpc];
            m[a[j]]=_29sumgpc;
            _29sumgpc++;


        }
    }
    for(int i=1;i<y;i++){
        cout<<x[i]-1<<' ';
    }cout<<x[y];
    return 0;
}
