#include<bits/stdc++.h>
using namespace std;
long long a[100000];
char c[100000];
char x[100000];
char y[100000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    int cnt=0;
    int num=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];

        for(int j=1;j<=a[i];j++){
            cnt++;
            x[cnt]=c[i];
            y[i]=x[i];
            ans++;
        }

    }
    if(ans%2==0){
        for(int i=ans+1;i>=ans/2;i--){
            x[i]=x[ans-i];
        }
        for(int i=ans/2+1;i<=ans;i++){
            if(x[i]!=y[i]){
                num++;
            }
        }
        cout<<num;
    }else{
        for(int i=ans+1;i>=ans/2+1;i--){
            x[i]=x[ans-i];
        }for(int i=ans/2;i<=ans;i++){
            if(x[i]!=y[i]){
                num++;
            }
        }
        cout<<num;
    }



    return 0;
}


