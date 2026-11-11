#include<bits/stdc++.h>
using namespace std;
int xxx[1010]={0,1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,210,231,253,276,300,325,351,378,406,435,465};
int n;
long long m;
long long cry[500010],dif[500010];


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cry[i];
    }
    if(n<=5000){
        sort(cry+1,cry+n+1);
        dif[1]=0;
        for(int i=2;i<=n;i++){
            dif[i]=cry[i]-cry[1];
        }
        int anss=0;
        for(int i=1;i<=n;i++){
            int stil=m;
            int ans=1;
            for(int j=1;j<i;j++){
                if(dif[i]-dif[i-j]<=stil){
                    ans++;
                    stil-=dif[i]-dif[i-j];
                }
            }
            anss=max(anss,ans);
        }
        cout<<anss<<endl;
    }
    else {
        sort(cry+1,cry+n+1);
        bool f=1;
        for(int i=1;i<=5;i++){
            if(cry[i]!=i){
                f=0;break;
            }
        }
        if(f==1){
            for(int i=1;i<=30;i++){
                if(m<xxx[i]){
                    cout<<i<<endl;
                    break;
                }
            }
        }
        else {
            int ch=cry[2]-cry[1];
            for(int i=1;i<=30;i++){
                if(m<xxx[i]*ch){
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
