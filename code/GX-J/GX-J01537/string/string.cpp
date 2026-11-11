#include<bits/stdc++.h>
using namespace std;
string c,b[1000005],d[1000005];
int n,a,l,p;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        l+=a;
        for(int j=1;j<=a;j++){
            b[i]=c;
        }
    }
    int y=l;
    for(int i=1;i<=l;i++){
        for(int j=y;j>=0;j--){
            b[i]=d[j];
            y=y-1;
        }
    }
    if(b==d){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=l;i++){
        if(d[i]!=b[i]){
            p+=1;
        }
    }
    cout<<p;
    return 0;
}
