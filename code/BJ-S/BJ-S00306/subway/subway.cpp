#include<bits/stdc++.h>
using namespace std;
int a[510][21];
int b[200010];
string s[2000010];
int main(){
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        int j=0;
        while(cin>>a[i][j]){
            s[a[i][j]]+=(n/100%10+'0')+(n/10%10+'0')+(n%10+'0');
            j++;
        }
    }
    int ans=0;
    int u=0;
    int n1=0;
    while(q--){
        int x=0,y=0;
        cin>>x>>y;
        while(y==x){
            for(int i=n-1;i>=0;i++){
                if(s[n].find(y)){
                    if(b[y]>u  || y==x){
                        n1=n;
                        u=b[y];
                    }
                }
            }
            ans+=u;
            y=n1;
        }
    }
    return 0;
}
