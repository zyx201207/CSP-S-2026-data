#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long a[200005];
string b,an;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];j++){
            an+=b;
        }

    }
    if(an.size()%2==0){
        string l,r;
        for(int i=0;i<=an.size()/2-1;i++){
            l+=an[i];
        }
        for(int i=an.size();i>an.size()/2;i--){
            r+=an[i];
        }
        for(int i=0;i<=an.size()/2-1;i++){
            if(l[i]!=r[i]) ans+=1;
        }
    }
    else{
        string l,r;
        for(int i=0;i<an.size()/2;i++){
            l+=an[i];
        }
        for(int i=an.size();i>an.size()/2+1;i--){
            r+=an[i];
        }
        for(int i=0;i<=an.size()/2-1;i++){
            if(l[i]!=r[i]) ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
