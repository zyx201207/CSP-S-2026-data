#include<bits/stdc++.h>
using namespace std;
long long n,m,i,a[1000010],b[300010];
long long l,p,q,o;
long long cntt[3000010];
long long vvv[3000010];
vector<long long> v[3000010];
long long t[3000010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
        v[a[i]].push_back(i);
        vvv[i]=cntt[a[i]]+1;
        cntt[a[i]]+=1;
    }
    for(l=0;l<n;l++){
        memset(b,0,sizeof(b));
        for(i=l;i<n;i++){
            if( (vvv[i]>1) && v[ a[i] ][(vvv[i]-2)] >=l &&b[v[ a[i] ][(vvv[i]-2)]]==0){
                for(o=v[ a[i] ][(vvv[i]-2)];o<i;o++){
                    b[o]=1;
                }
            }
        }
        for(i=l;i<n;i++){
            if(b[i]==0){
                t[a[i]]++;
            }
        }
    }
    for(i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
