#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0,a[100010];
    string c[100010],b[100010];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];i++){
            b[i]=c[i];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=n-1;j>=0;j--){
            if(b[i]!=b[j]){
                b[i]=b[j];
                cnt+=1;
                break;
            }
            else break;
        }
    }
    cout<<cnt;
    return 0;
}
