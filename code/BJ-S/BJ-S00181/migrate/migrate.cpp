#include<bits/stdc++.h>
using namespace std;
long long p[2000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        int cnt = 0;
        cin>>n>>d;
        for(int f = 1; f<=n; f++){
            cin>>p[f];
        }
        for(int f = 1; f<=n; f++){
            for(int e = f+1; e<=n; e++){
                if(p[e]-p[f]<=d) continue;
                int c = 0;
                for(int s = f+1; s<e; s++){
                    if(p[s]-p[f]<=d&&p[e]-p[s]<=d){
                        c++;
                    }
                }
                if(c == 2){
                    //cout<<f<<' '<<e<<"\n";
                    cnt++;
                }
            }
        }
        cout<<cnt;
    }
    return 0;
}
