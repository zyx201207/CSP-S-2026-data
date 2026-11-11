#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],c[2][300010],an[300010],lin[500010];
int l=1;
struct ll{
    int ans;
    int next=-1;
}b[500010];
void lian(int as,int t){
    for(t=t;t!=-1;t=b[t].next){
        if(b[t].next==-1){
            l++;
            b[l].ans=as;
            b[t].next=l;
            break;
        }
    }
    return;
}
const int zt(int t,int ss){
    for(t=t;t!=-1;t=b[t].next){
        if(lin[b[t].ans]==0){
            return b[t].ans;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[0][a[i]]++;
        if(c[1][a[i]]==0){
            c[1][a[i]]=++l;
            b[l].ans=i;
        }
        else{
            lian(i,c[1][a[i]]);
        }
    }
    for(int i=1;i<=n;i++){
        int s=i-1;
        for(int j=1;j<=s;j++){
            lin[j]=1;
        }
        for(int j=i;j<=n;j++){
            if(c[0][a[j]]>1){
                if(zt(c[1][a[j]],s)<j){
                    int tt=zt(c[1][a[j]],s);
                    s=j-1;
                    for(int k=tt;k<=s;k++){
                        lin[k]=1;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(lin[j]==0){
                an[a[j]]++;
            }
            lin[j]=0;
        }
    }
    int w;
    for(w=1;w<=m;w++){
        cout<<an[w]<<' ';
    }
    return 0;
}
