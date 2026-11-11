#include<bits/stdc++.h>
using namespace std;
int n,g;
int m[1145141];
char a[1145141];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %c",m+i,a+i);
    }
    int x=1,y=n;
    while(x<y){
        int b=min(m[x],m[y]);
        if(a[x]!=a[y]) ans+=b;
        m[x]-=b;m[y]-=b;
        if(m[x]==0) x++;
        if(m[y]==0) y--;
    }
    printf("%lld",ans);
    return 0;
}
