#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int N=2e5+1;
int n,ans;
struct node{
    int cnt;
    char c;
}a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld %c",&a[i].cnt,&a[i].c);
    }
    int i=1,j=n;
    while(i<j){
        if(a[i].cnt>a[j].cnt){
            if(a[i].c!=a[j].c){
                ans+=a[j].cnt;
            }
            a[i].cnt-=a[j].cnt;
            j--;
        }else if(a[i].cnt<a[j].cnt){
            if(a[i].c!=a[j].c){
                ans+=a[i].cnt;
            }
            a[j].cnt-=a[i].cnt;
            i++;
        }else{
            if(a[i].c!=a[j].c){
                ans+=a[i].cnt;
            }
            i++;
            j--;
        }
    }
    printf("%lld",ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
