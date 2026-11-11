#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,c,d;
char b[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    if(n%2==1){
        for(int i=1;i<=(n-1)/2;i++){
            for(int j=n;j>=(n+1)/2;j--){
                if(b[i]==b[j]){
                    c+=a[i]-a[j];
                }
                else{
                    if(a[i]>=a[j]){
                        d+=a[j];
                    }
                    else{
                        d+=a[i];
                    }
                }
            }
        }
        d+=c;
    }
    if(n%2==0){
        for(int i=1;i<=n/2;i++){
            for(int j=n;j>=n/2+1;j--){
                if(b[i]==b[j]){
                    c+=a[i]-a[j];
                }
                else{
                    if(a[i]>=a[j]){
                        d+=a[j];
                    }
                    else{
                        d+=a[i];
                    }
                }
                cout<<c;
            }
        }
        d+=c;
    }
    cout<<d;
    return 0;
}
