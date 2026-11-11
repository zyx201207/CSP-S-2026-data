#include<bits/stdc++.h>
using namespace std;
int b[30];
struct st{
    char x;
    int y;
};

int main(){
    freopen("string4.in","r",stdin);
    freopen("string4.out","w",stdout);
    int n,a;
    long long int b=0,d=0;
    st z[200005];
    int h=0,l=0;
    char m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>m;
        b+=a;
        z[i].x=m;
        z[i].y=a;
    }
    long long int c=b/2;
    while(c>0){

        if(z[1+h].y>z[n-l].y){
            if(z[1+h].x!=z[n-l].x){
                c-=z[n-l].y;
                d+=z[n-l].y;
                z[1+h].y-=z[n-l].y;
                z[n-l].y-=z[n-l].y;
                d+=z[n-l].y;
                l++;

            }
            else{
                c-=z[1+h].y;
                z[1+h].y-=z[n-l].y;
                z[n-l].y-=z[n-l].y;
                l++;
            }
        }
        else{
            if(z[1+h].x!=z[n-l].x){
                c-=z[1+h].y;
                d+=z[1+h].y;
                z[1+h].y-=z[1+h].y;
                z[n-l].y-=z[1+h].y;
                h++;


            }
            else{
                c-=z[1+h].y;
                z[1+h].y-=z[1+h].y;
                z[n-l].y-=z[1+h].y;
                h++;
            }
        }


    }
    cout<<d;










    return 0;
}
