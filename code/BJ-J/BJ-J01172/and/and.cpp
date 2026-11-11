#include<bits/stdc++.h>
using namespace std;
int n,m,pmx[200005],a[200005],cnt[35],mp[200005][35];
bool tf[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int aa=a[i];
        pmx[i]=max(pmx[i-1],a[i]);
        if(i==1) ans=a[i];
        else ans=ans&a[i];
        int w=0;
        while(aa){
            w++;
            if(aa%2==1){
                mp[i][w]=1;
                cnt[w]+=1;
                aa-=1;
            }
            aa/=2;
        }
    }
    int anss=0;
    for(int i=1;i<=n;i++) tf[i]=true;
    for(int i=31;i>=1;i--){
        int no=1<<(i-1),cnt=0;
        for(int i=1;i<=n;i++){
            if(no&a[i]&&tf[i]==true){
                cnt++;
            }
        }
        if(cnt>=m){
            for(int i=1;i<=n;i++){
                if(!(no&a[i])&&tf[i]){
                    tf[i]=false;
                }
            }
            anss+=no;
        }
    }
    cout<<anss;
    return 0;
}
