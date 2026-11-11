#include<bits/stdc++.h>
using namespace std;
int l[200005];
vector<int>usen;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        scanf("%d",&l[i]);
        usen.push_back(l[i]);
    }
    bool havemax=0;
    for(int pos=30;pos>=0;pos--){//30*2*n why time out?
        int cnt=0;
        for(int i = 0;i<usen.size();i++){
            if(usen[i] & 1<<pos)cnt++;
        }
        if(cnt>=m){
            for(int i = 0;i<usen.size();i++){
                if(!(usen[i] & 1<<pos)){
                    usen.erase(usen.begin()+i);
                    i--;
                }
            }
        }
    }
    ans=usen[0];
    for(int i=1;i<usen.size();i++){
        ans&=usen[i];
    }
    cout<<ans;
    return 0;
}
