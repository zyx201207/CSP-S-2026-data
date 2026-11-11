#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e6 +5;
const unsigned long long maxd = 10e7 +10;

long long c,t,n;
long long island[maxn];
long long d,modded;
long long modD[maxd];
long long lastmodD[maxd],ans=0;
long long maxmodded;
bool edited[maxd];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin.tie(0);
    
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        ans=0;
        maxmodded=0;
        for(int i= 1; i <= n; i++) cin >> island[i];
        for(int i = 0; i <= maxmodded+1; i++){modD[i]=0;lastmodD[i]=0;edited[i]=0;}
        if(d<=maxd){
            for(int i = 1; i <= n; i++){
                if(island[i]-island[i-1]>d) {for(int i = 0; i <= maxmodded+1; i++){modD[i]=0;lastmodD[i]=0;edited[i]=0;}}
                modded = ((island[i]%d)+d)%d;
                if(!edited[modded]){edited[modded]=1; lastmodD[modded] = island[i];}
                else{
                    ans+=modD[(modded+1)%d]-(island[i]-lastmodD[(modded+1)%d]<=2*d)?1:0;
                    lastmodD[modded] = island[i];
                }
                modD[modded]++;
                maxmodded = max(maxmodded,modded);
            }
        }
        
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}