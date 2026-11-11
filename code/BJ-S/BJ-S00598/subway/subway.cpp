#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[500005],s[500005][500005][2],line;
void temp7to11(){
    for(int i=0;i<m;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>line;
        for(int j=0;j<line;j++) cin>>s[i][j][0]>>s[i][j][1];
    }
    while(q--){
        long long start,endn;
        cin>>start>>endn;
        for(int i=0;i<n;i++){
            if(s[0][i][0]==start){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        if(s[0][k][0]==s[0][j][0]){
                            cout<<a[start]+a[endn]+s[0][j][1]+s[0][k][1];
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c>=7&&c<=11){
        temp7to11();
        return 0;
    }
    return 0;
}