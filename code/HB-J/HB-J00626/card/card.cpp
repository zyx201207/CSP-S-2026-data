#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
const ll M=3e5+5;
ll n,m;
ll a[N],b[M];
vector< vector<ll> > p;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    p.resize(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[a[i]].push_back(i);
    }
    for(int y=0;y<n;y++){
        for(int i=n;i>y;i--){

            if(p[a[i]].size()==1) {
                    b[a[i]]++;
                    continue;
            }
            for(int j=0;j<p[a[i]].size()-1;j++){
                if(p[a[i]][j]>y){
                    i=p[a[i]][j];
                    break;
                }
            }
        b[a[i]]++;

        }
    }
    for(int i=1;i<=m;i++) cout<<b[i]<<' ';
    return 0;

}
