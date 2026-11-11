#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string2.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int a[1000005];
    char c[1000005];
    cin>>n;
    for(int i=0;i<=n-1;i++){
        cin>>a[i]>>c[i];
    }
    if(n<=1){
        cout<<"0";
        return 0;
    }
    if(n<=2){
        if(c[0]=c[1]){
            cout<<0;
            return 0;
        }
        if(a[0]>a[1]){
            cout<<a[1];
            return 0;
        }
        else if(a[0]<a[1]){
            cout<<a[0];
            return 0;
        }
        else if(a[0]==a[1]){
            cout<<a[0];
            return 0;
        }
    }
    n=0;
    for(int i=0;i<=200000;i++){
        for(int j=i;j<=200000;j++){
            if(c[i]==c[j+1]){
                a[i]+=a[j+1];
                a[j+1]=0;
            }
            else if(a[j+1==0]){
                continue;
            }
            else{
                a[i+1]=a[j+1];
                c[i+1]=c[j+1];
                n++;
                break;
            }
        }
    }
    if(c[1]=0){
        cout<<0;
    }
    return 0;
}
