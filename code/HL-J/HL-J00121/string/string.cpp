#include<bits/stdc++.h>
using namespace std;
int n,a[200001],cnt;
char c[200002];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    string s;
    for(int i=0;i<=n;i++){
        for(int j=0;j<a[i];j++){
            s[j]=c[i];
            //cout<<s[j];
        }
    }
    string q;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<a[i];j++){
            q[j]=c[i];
            if(q[j]!=s[j]){
                cnt++;
            }
        }
    }


    cnt/=2;
    cout<<cnt*2;
    return 0;
}
