#include <bits/stdc++.h>
using namespace std;
int n,num=1,ff=0;
char c[200005]={'+'},d[200005];
unsigned long long len,xx=0,x=1,y,yy,tot=0,a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[num]>>c[num];
        d[i]=c[num];
        if(a[i]!=1)ff=1;
        len+=a[num];
        if(c[num]==c[num-1]){
            a[num-1]+=a[num];
        }
        else {
            num++;
        }
    }
    if(ff==0){
        for(int i=1;i<=n/2;i++){
            if(a[i]!=a[n-i+1])tot++;
        }
        cout<<tot;
    }
    else {
        y=num-1;
        yy=len+1;
       while(xx<yy&&x<=y){
            xx+=a[x];
            x++;
            if(xx>=yy||x-1>=y)break;
            while(yy>=len-xx+1){
                yy-=a[y];
                if(yy<len-xx+1)break;
                if(c[y]!=c[x-1]){
                    tot+=a[y];
                }
                y--;
            }

            if(yy+a[y]-1>=len-xx+1){
                if(c[y]!=c[x-1]){
                    tot+=yy+a[y]-1-len+xx;
                }
            }
            yy=len-xx+1;
        }
        cout<<tot;
    }

    return 0;
}
