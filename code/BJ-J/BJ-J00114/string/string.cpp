#include<bits/stdc++.h>
using namespace std;
int n;
long long a[10006],ji=0,cnt=0;
string c,s;
int main(){
    set<char> aa;
     freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);

     cin>>n;
     for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        cnt+=a[i];
        for(int j=1;j<=a[i];j++){
                ji++;
            s[ji]=c[i];
            aa.insert(c[i]);
        }
     }
     if(aa.size()==1){
        cout<<0;
        return 0;
     }
    string l,r;
    for(int i=1;i<=cnt/2;i++){
        l[i]=s[i];
    }
    for(int i=cnt;i>=cnt/2+1;i--){
        r[i]=s[i];
    }
    int ans=0;
    for(int i=1;i<=cnt/2;i++){
        if(l[i]!=r[i]){
            ans++;
        }
    }
    cout<<ans;

    return 0;
}
