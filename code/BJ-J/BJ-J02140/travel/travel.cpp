#include<bits/stdc++.h>
using namespace std;
int a[4]={0,0,0,0};
string q,w,e,r;
int x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    cin>>q>>w>>e>>r;
    if(q==e){
        a[0]=1;
        if(w[0]==r[0]&&w[1]==r[1]){
            a[1]=1;
            x=w[2];
            y=r[2];
            if((x<58&&y<58)||(x>57&&y>57)){
                a[2]=1;
                int n=x-y;
                if(n==-1||n==1) a[3]=1;
            }
        }
    }
    cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0;
}

