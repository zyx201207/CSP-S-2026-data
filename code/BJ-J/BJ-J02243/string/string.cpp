#include<bits/stdc++.h>
using namespace std;
int main(){
freopen ("string.in","r",stdin);
freopen("string","w",stdout);
string a[100005],b[100005];
int n,cnt=0;
cin>>n;
for(int i=1;i<=n;i++){
    cin<<a[i];

for(int i=n;i>=1;i--){
    if(b[i]==a[i]{
       cout<<0;
    }else{
        if(a[i]%2==0){
        for(int i=1;i<=n;i++){
        if(a[i-n+1]!='a'){
            a[i-n+1]='a';
            cnt++;
            if(a[n]!='a'){
            a[n]='a';
            }
            cnt++;
            }
            if(b[i]==a[i]){
                cout<<cnt;
                }
                }
            }else{
            for(int i=1;i<=n;i++){
            if(a[i-1]!='a'){
                a[i-1]='a';
                }
                cnt++;
                if(a[i+1]!='a'){
                a[i+1]='a';
                }
                cnt++;
                if(b[i]==a[i]){
                cout<<cnt;
                }
                }

            }

    }
    }
    }
return 0;
}
