#include <bits/stdc++.h>
using namespace std;
struct q{
    int a[100005];
    int b[100005];
}s[505];
int main(){
    int e[1000];

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,x,t,y;
    cin>>c>>n>>m>>d>>q;
    for(int i;i<m;i++){
        cin>>e[i];
    }
    for(int i;i<n;i++){
        cin>>t;
        for(int j;j<t;j++){
            cin>>s[i].a[j]>>s[i].b[j];
        }
    }
    for(int i=0;i<q;i++){
        cin>>x>>y;
        for(int j=0;j<n;j++){
            for(int p=0;p<e[j];p++){
                if(s[j].a[p]==x){
                    for(int o=0;o<e[j];o++){
                        if(s[j].a[o]==y){
                            cout<<s[j].b[p]+s[j].b[o];
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
