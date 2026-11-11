#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,cnt=0,a[100010],b[100010];
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=i;i++){
        b[i-cnt]=a[i-cnt];
        for (int j=0;j<i;j++){
            if (b[i]==b[j]){
                cnt=j-i;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]>b[i]){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
