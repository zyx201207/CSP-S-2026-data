#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Lsti{
    int v;
    char m;
}wod[200010];
int a,tmp,ans;
char ctmp;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    scanf("%lld",&tmp);
    scanf("%c",&ctmp);scanf("%c",&ctmp);
    wod[1].m=ctmp;wod[1].v=tmp;
    for(int i=2;i<=a;i++){
        scanf("%lld",&tmp);
        scanf("%c",&ctmp);scanf("%c",&ctmp);
        if(ctmp==wod[i-1].m){
            wod[i-1].v+=tmp;a--;i--;
            continue;
        }else{
            wod[i].m=ctmp;wod[i].v=tmp;
        }
    }
    for(int i=1,j=a;i<j;){
        int xi=wod[i].v,yi=wod[j].v;
        if(wod[i].m!=wod[j].m){
            if(xi>yi){
                wod[i].v-=yi;ans+=yi;
                j--;
            }else if(xi<yi){
                wod[j].v-=xi;ans+=xi;
                i++;
            }else{
                ans+=xi;
                i++;j--;
            }
        }else if(wod[i].m==wod[j].m){
            if(xi>yi){
                wod[i].v-=yi;
                j--;
            }else if(xi<yi){
                wod[j].v-=xi;
                i++;
            }else{
                i++;j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
//Trick||Treat!
