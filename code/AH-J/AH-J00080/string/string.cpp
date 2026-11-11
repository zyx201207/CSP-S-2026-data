#include <bits/stdc++.h>
using namespace std;
int n,a[10100],a1[10100];long long l = 0,cnt=0;
char c[10100],c1[10100],b[210000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        a1[i] = a[i];
        cin>>c[i];
        c1[i] = c[i];
    }sort(c1,c1+n);
    sort(a1,a1+n);
    if(c1[0] == c1[n-1]){
        cout<<0;
        return 0;
    }
    if(a1[0] == a1[n-1]){
        for(int i = 0;i < n/2;i++){
            if(c[i] != c[n-i+1]){
                cnt++;
            }
        }
        cout<<cnt*a1[0];
        return 0;
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < a[i];j++){
            b[l] = c[i];
            l++;
        }
    }
    for(int i = 0;i < l/2;i++){
        if(b[i] != b[n-i+1]){
            cnt++;
        }else{
            cout<<b[i]<<" "<<b[n-i+1]<<endl;
        }
    }
    cout<<cnt;
    return 0;
}
