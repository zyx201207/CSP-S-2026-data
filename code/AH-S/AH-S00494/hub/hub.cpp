#include<bits/stdc++.h>
using namespace std;
int c,t,n,u,v,fl,pos,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        fl=0,pos=0;
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            if(u==1){
                if(!fl)fl=1;
                else pos=i-1;
            }
        }
        printf("%d\n",pos-k/2);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
