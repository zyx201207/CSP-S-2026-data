#include<bits/stdc++.h>
using namespace std;
int s[100];
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
   int n,m;
   cin>>n>>m;

   int x=1,y=1;
   int a[10000];
   for(int i=1;i<=n;i++){
    cin>>a[i];
   }int b[10000];
   for(int i=10;i>=1;i--){
    for(int j=11-i;j<=10;j++){
        b[x]=a[j];
        for(int h=1;h<=x;h++){
            if(b[x]==b[h]){
                for(int g=h+1;g<=x;g++){
                    b[g]=0;
                }
            x=h;
                break;
            }x++;
    }
    }cout<<b<<" ";
    for(int f=1;f<=m;f++){
        for(int g=1;g<=x;g++){
            if(b[g]==i){
                s[i]++;
            }
        }
    }

    for(int w=1;w<=x;w++){
        b[w]=0;
    }
   }x=1;
   cout<<s;
    return 0;
}

