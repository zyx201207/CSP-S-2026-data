#include<bits/stdc++.h>
using namespace std;
long long c[100000000],d[10000],e;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    for(int j=0;j<a;j++){
        for(int i=1;i<=a;i++){
                d[i]=0;
        }
        for(int i=0;i<a;i++){
            e+=c[i];
            d[c[i]]++;
            if(e==b){
                e=0;
                for(int i=1;i<=a;i++){
                    d[i]=0;
                }
            }
        
        }
        for(int i=1;i<=a;i++){
            cout<<d[i];
        }
    }
    
    


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long c[100000000],d[10000],e;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    for(int j=0;j<a;j++){
        for(int i=1;i<=a;i++){
                d[i]=0;
        }
        for(int i=0;i<a;i++){
            e+=c[i];
            d[c[i]]++;
            if(e==b){
                e=0;
                for(int i=1;i<=a;i++){
                    d[i]=0;
                }
            }
        
        }
        for(int i=1;i<=a;i++){
            cout<<d[i];
        }
    }
    
    


    return 0;
}
