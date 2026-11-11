#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[10];
int b[10];
int c=0;
int d1,d2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        for(char i:s1){
            a[i]=i;
        }
        for(char j:s2){
            b[j]=j;
        }
        for(int k=0;k>3;k++){
            if(a[k]==b[k]){
                if(k<=2){
                    c++;
                }else{
                    d1=a[k];
                    d2=b[k];
                }
            }
        }
        if(c==2){
            cout<<1;
        }else{
            cout<<0;
        }
        if(d1<68&&d2<68){
                cout<<1;
                if(d1-d2==1){
                    cout<<1;
                }else{
                    if(d2-d1==1){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }
        }else{
            if(d1>67&&d2>67){
                   if(d1-d2==1){
                   cout<<1;
                }else{
                    if(d2-d1==1){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }
            }else{
                cout<<0;
            }
        }
    }else{
        cout<<0000;
    }
    return 0;
}
