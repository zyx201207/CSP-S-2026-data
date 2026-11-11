#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a;
    char m;
}g[300005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,f,k,num=0;
    k=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>g[i].a>>g[i].m;
    }
    f=n;
    while(f>k){
        if(g[f].a>g[k].a){
            if(g[f].m==g[k].m){
                g[f].a-=g[k].a;
                k++;
            }else{
                num+=g[k].a;
                g[f].a-=g[k].a;
                k++;
            }
        }else if(g[f].a<g[k].a){
            if(g[f].m==g[k].m){
                g[k].a-=g[f].a;
                f--;
            }else{
                num+=g[f].a;
                g[k].a-=g[f].a;
                f--;
            }
        }else{
            if(g[f].m==g[k].m){
                k++;
                f--;
            }else{
                num+=g[k].a;
                k++;
                f--;
            }
        }
    }
    cout<<num;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
