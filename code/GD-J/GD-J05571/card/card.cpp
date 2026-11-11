#include <bits/stdc++.h>
using namespace std;
long long n,m;
cin>>n>>m;
long long d[n];
void game(n){
    long long desk[n];
    long long h=0;
    for(int i=0;i<n;i++){
        desk[i]=d[h];
        for(int j=0;j<i;j++){
            if(desk[i]==desk[j]){
                for(int l=j+1;l<=j;l++){
                    desk[l]=-1;
                }
            }
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    int a1,a2;
   for(int i=1;i<n;i++){
        game(n,d[i]);
        for(i=0,i<n;i++){
            if(desk[i]==d[0]){
                a1+=1
            }
            if(desk[i]==d[1]){
                a2+=1;
            }
        }
   }
   cout<<a1<<' '<<a2;
   return 0;
}
