#include<bits/stdc++.h>
using namespace std;
struct block{
    int num;
    char ch;
}f[200010];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i].num);
        cin>>f[i].ch;
    }
    int l=1,r=n;
    long long ans=0;
    while(true){
        if(l==r) break;
        if(l>r) break;
        if(f[l].ch==f[r].ch){
            if(f[l].num>f[r].num){
                f[l].num-=f[r].num;
                f[r].num=0;
                r--;
            }
            else if(f[r].num>f[l].num){
                f[r].num-=f[l].num;
                f[l].num=0;
                l++;
            }
            else if(f[l].num==f[r].num){
                f[l].num=0;
                f[r].num=0;
                r--,l++;
            }
        }
        else if(f[l].ch!=f[r].ch){
            if(f[l].num>f[r].num){
                f[l].num-=f[r].num;
                ans+=f[r].num;
                f[r].num=0;
                r--;
            }
            else if(f[r].num>f[l].num){
                f[r].num-=f[l].num;
                ans+=f[l].num;
                f[l].num=0;
                l++;
            }
            else if(f[l].num==f[r].num){
                ans+=f[l].num;
                f[l].num=0;
                f[r].num=0;
                r--,l++;
            }
        }
    }
    printf("%lld",ans);
}
