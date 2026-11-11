#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int q=1111,w=1110,e=1100,r=1000,t=0000;
    char a,c;
    char b[30][10],d[30][10];
    cin>>a>>b>>c>>d;
    if(a==c){
        for(int i =1; i<=18;i++){
            for(int  j= 1; j<=5;j++){
                if(b[i]==d[i]){
                    if(b[j]<=3 && d[j]<=3 || b[j]>3 && d[j]>3){
                        if(b[i][j+1]==d[i][j] || b[i][j]==d[i][j+1]){
                            cout<<q;
                        }
                        else{
                            cout<<w;
                        }
                    }
                    else{
                        cout<<e;
                    }
                }
                else{
                    cout<<r
                }
            }
        }
    }
    else{
        cout<<t;
    }
    return 0;
}
