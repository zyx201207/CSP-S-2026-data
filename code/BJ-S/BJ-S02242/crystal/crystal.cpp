#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 5e5+1;
int a[N];
int ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) flag=1;
    }
    int dengcha=1,dcnub;
    if(a[2]-a[1]==a[3]-a[2]){
        dengcha=0;
        dcnub=abs(a[2]-a[1]);
    }
    if(flag==0){
        int i=0;
        while(m-i>=0){
            ans++;
            m-=i;
            i++;
        }
        cout<<ans<<'\n';
        return 0;
    }else if(dengcha==0){
        int i=0;
        while(m-i*dcnub>=0){
            ans++;
            m-=i*dcnub;
            i++;
        }
        cout<<ans<<'\n';
        return 0;
    }else{
        int cha[n+1];
        for(int i=1;i<n;i++){
            cha[i]=a[i+1]-a[i];
        }
        for(int i=1;i<n;i++){
                int tot=0;
                int num=0;
            for(int j=i;j<n;j++){
                if(tot+cha[i]>m) break;
                tot+=cha[j];
                num++;
            }
            ans=max(ans,num);
        }
        cout<<ans<<'\n';
        return 0;
    }
    return 0;
}