#include<bits/stdc++.h>
using namespace std;
long long int a,b;
string aa,bb;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.ans","w",stdout);
    cin>>a>>aa>>b>>bb;
    if(a!=b){
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }else{
        cout<<1;
        if(aa[1]==bb[1]&&aa[0]==bb[0]){
            cout<<1;
            int x=aa[2],y=bb[2];
            if(x==68||x==69){
                if(y==68||y==69){
                    cout<<11;
                }else{
                    cout<<0;
                    cout<<0;
                }
            }else{
                if(y==67||y==66||y==65){
                    cout<<1;
                    if(abs(y-x)==1){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }
                else{
                    cout<<0;
                    cout<<0;
                }
            }
        }else{
            cout<<0;
            cout<<0;
            cout<<0;
            }
    }
}
