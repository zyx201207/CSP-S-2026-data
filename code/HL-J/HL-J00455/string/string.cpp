#include<bits/stdc++.h>
using namespace std;
long long n[100000];
char c[100000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int w;
    cin>>w;
    for(int i=0;i<w;i++){
        cin>>n[i];
        cin>>c[i];

    }
    int sum1=0;
    int sum2=0;
    int p=0,q=0;
    int sum0=0;
    int o=w;
    for(int i=0;i<w;i++){
        sum0+=n[i];
    }
    if(sum0%2==0){
        for(int j=0;j<sum0/2;j++){
            sum1+=n[j];
        }
        for(int k=sum0/2;k<sum0;k++){
            sum2+=n[k];
        }
        p=max(sum1,sum2);
        for(int i=0;i<sum0/2;i++){
            for(int j=sum0/2;j<sum0;j++){
                if(c[i]==c[j]){
                    p-=abs(n[i]-n[j]);
                }
            }
        }
        cout<<p;
        return 0;
    }else{
        for(int j=0;j<sum0/2-1;j++){
            sum1+=n[j];
        }
        for(int k=sum0/2+1;k<sum0;k++){
            sum2+=n[k];
        }
        q=max(sum1,sum2);
        for(int i=0;i<sum0/2;i++){
            for(int j=sum0/2;j<sum0;j++){
                if(c[i]==c[j]){
                    q-=abs(n[i]-n[j]);
                }
            }
        }
        cout<<q+1;
    }




    return 0;
}

