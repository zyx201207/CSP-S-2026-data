#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005];
vector<long long> d;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=0;k<d.size();k++){
                if(d[k]==a[j]){
                    for(int l=k;l<d.size();l++) d[l]=0;
                }
            }
            d.push_back(a[j]);
        }
        for(int j=0;j<d.size();j++) if(d[j]!=0) b[d[j]]++;
        d.erase(d.begin(),d.end());
    }
    for(int i=1;i<=m;i++) printf("%lld ",b[i]);
    return 0;
}
