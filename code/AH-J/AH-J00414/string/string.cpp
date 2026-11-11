#include<bits/stdc++.h>
using namespace std;
long long n,cnt,b;
long long a;
char c;
string d,d1,d2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            d+=c;
        }
    }
    int l=d.size();
    if(l%2)l--;
    d1=d.substr(0,l);
    d2=d.substr(l,l+1);
    reverse(d2.begin(),d2.end());
    b=0;
    if(d1==d2){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<l;i++){
        if(d1[i]!=d2[i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
