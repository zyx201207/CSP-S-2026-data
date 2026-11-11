#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+100;
int n,m,j;
int a[N],b[N],s[N];
void ff(int x){
    if(x>n){
        for(int i=1;i<=j;i++){
            if(s[i]!=0){
                b[s[i]]++;
            }
            s[i]=0;
        }
        j=0;
        return ;
    }
    bool f=false;
    for(int i=1;i<=j;i++){
        if(f){
            s[i]=0;
        }else if(s[i]==a[x]){
            f=true;
        }
    }
    if(!f){
        j++;
        s[j]=a[x];

    }
    ff(x+1);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ff(i);
    }
    cout<<b[1];
    for(int i=2;i<=m;i++){
        cout<<" "<<b[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
