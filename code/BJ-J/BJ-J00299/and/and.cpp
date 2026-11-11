#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[200005][35];
int k=0,mx=0;
void ak(int l,int i){
    int y=0;
    while(l!=0){
        b[i][y]=l%2;
        l/=2;
        y++;
    }
    if(k<y){
        mx=i;
    }
    k=max(k,y);
}
int pa(int ws[]){
    int ans=0;
    for(int i=0;i<35;i++){
        ans+=ws[i]*pow(2,i);
    }
    return ans;
}
int comp(int i,int j){
    int mob[35];
    for(int i=0;i<35;i++){
        if(b[j][i]&&b[i][i])mob[i]=1;
        else mob[i]=0;
    }
    return pa(mob);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ak(a[i],i);
    }
    if(m==1){
        cout<<a[mx];
        return 0;
    }
    queue <int>pi;
    bool flag=false;
    for(int i=k-1;i>=0;k--){
        if(flag)break;
        for(int j=0;j<n;j++){
            if(j==mx)continue;
            if(b[j][i]==b[mx][i]){
                pi.push(j);
                flag=true;
            }
        }
    }
    int ans=0;
    while(!pi.empty()){
        int ad=pi.front();
        pi.pop();
        ans=max(ans,comp(mx,ad));
    }
    cout<<ans;
    return 0;
}
