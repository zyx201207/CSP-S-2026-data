#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int n[a];
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    int x,y;
    int axy;
    int xy[a-1];
    for(int i=0;i<a-1;i++){
        x=n[i];
        y=n[i+1];
        int ax=0,ay=0,xn=1,yn=1;
        for(int i=0;i=x/2+1;i++)
            ax=ax*10+x%2;
            xn*=10;
        for(int i=0;i=y/2+1;i++)
            ay=ay*10+y%2;
            yn*=10;
        if(ax>ay){
            axy =(ax-ay)/yn;
        }
        else{
            axy =(ay-ax)/xn;
        }
        xy[i]=axy;
    }
    int maxn=0;
    for(int i=0;i<a-1;i++){
        if(maxn<xy[i]){
            maxn=xy[i];
        }
    }
    int maxm=0;
    for(int i=0;i<maxn/10;i++){
        maxm=maxn%10*pow(2,i);
    }
    cout <<maxm;
    return 0;
}
