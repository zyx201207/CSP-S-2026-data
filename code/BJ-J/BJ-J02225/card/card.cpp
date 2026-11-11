#include<bits/stdc++.h>
using namespace std;
long long a[2000005],b,ans;
char c[2000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>b;
    for(int i=1;i<=b;i++){
        cin>>a[i]>>c[i];
    }
    long long g=1,d=b,e=a[1],f=a[b];
    while(1){
        if(g>=d){
            break;
        }
        if(e>f){
            if(c[g]!=c[d]){
                ans+=f;
            }
            e-=f;
            d--;
            f=a[d];
        }else if(f>e){
            if(c[g]!=c[d]){
                ans+=e;
            }
            f-=e;
            g++;
            e=a[g];
        }else{
            if(c[g]!=c[d]){
                ans+=e;
            }
            g++;
            e=a[g];
            d--;
            f=a[d];
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
