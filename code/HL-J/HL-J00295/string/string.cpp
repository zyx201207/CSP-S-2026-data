#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
char c;
long long s;
struct st{
    long long from,to;
    char w;
}h[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;
    int last=-1;
    for(int i=1;i<=n;i++){
        cin >> a >> c;
        h[i].from=last+1;
        h[i].to=last+a;
        h[i].w=c;
        last=h[i].to;
        s+=a;
    }
    /*for(int i=1;i<=n;i++){
        cout << h[i].from << h[i].to << h[i].w << "\n";

    }*/
    long long r=s-1,l=0,x=1,y=n;
    while(r>=l){
        if(r<h[y].from) y--;
        if(l>h[x].to) x++;
        //printf("x%d y%d r%d l%d",x,y,r,l);
        if(h[x].w!=h[y].w) ans++;
        l++,r--;
    }
    cout << ans;
    return 0;
}
