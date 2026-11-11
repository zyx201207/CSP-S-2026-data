#include<bits/stdc++.h>
using namespace std;
int a[500005];
int tot[300005];
int d[500005];
int in[300005];
int last[300005];//last is shangyici tail de place
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int h=1,t=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            d[t]=a[i];
            if(in[a[i]]==0){
                in[a[i]]=1;
                last[a[i]]=t;
                //if(a[i]==2)cout<<t<<endl;
                t++;
                //cout<<a[i]<<":"<<last[a[i]]<<endl;
                //cout<<t<<endl;
                continue;
            }
            else{
                for(int i=last[a[i]];d[i]!=0;i++){
                    in[d[i]]=0;
                }
                t=last[a[i]];
                //cout<<a[i]<<" "<<t<<endl;
                t++;
                //cout<<t<<endl;
                continue;
            }
        }
        for(int i=h;i<=t-1;i++){tot[d[i]]++;}
        h=1;
        t=1;
        memset(d,0,sizeof(d));
        memset(in,0,sizeof(in));
        memset(last,0,sizeof(last));
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<tot[i]<<" ";
    return 0;
}
