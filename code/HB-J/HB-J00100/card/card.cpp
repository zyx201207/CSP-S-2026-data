#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long a,b,n=0;
    cin>>a>>b;
    long long shou[a+10]={0},zhuo[a+10]={0},last[b+5]={0};
    for(int i=1;i<=a;i++){
        cin>>shou[i];
    }
    int j=1,s=0,w=1;
    while(true){
        if(j==a){
            last[shou[a]]++;
            break;
        }
        s=0;
        w=1;
        zhuo[1] = shou[j];
        for(int k=j;k<=a;k++){
            for(int i=1;i<=w;i++){
                if(shou[k]==zhuo[i] && shou[k]!=0){
                    s=i;
                    break;
                }
            }
            if(s!=0){
                w=s-1;
                for(int i=s;i<=a;i++){
                    zhuo[i]=0;
                }
                s=0;
            }
            zhuo[w+1] = shou[k];
            w++;
        }
        for(int k=1;k<=a;k++){
            last[zhuo[k]]++;
        }
        for(int i=1;i<=a;i++){
            zhuo[i]=0;
        }
        j++;
    }
    for(int i=1;i<=b;i++){
        cout<<last[i]<<" ";
    }
    return 0;
}
