#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    vector<long long>a;
    long long b[100000]={0};
    long long c[200000];
    long long sum[100000]={0};
    for(int i=0;i<n;i++){
        scanf("%lld",&c[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(b[c[j]]!=0){
                memset(b,0,sizeof(b));
                for(int k=0;k<a.size();k++){
                    if(a[k]==c[j]){
                        a.erase(a.begin()+k,a.end());
                        break;
                    }else{
                        b[a[k]]=k+1;
                    }
                }
            }

            a.push_back(c[j]);
            b[c[j]]=j-i+1;
        }
        for(int j=0;j<a.size();j++){
            sum[a[j]]++;
        }
        a.erase(a.begin(),a.end());

    }
    for(int i=1;i<=m;i++){
        printf("%lld ",sum[i]);
    }
    return 0;
}
