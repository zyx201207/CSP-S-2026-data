//*
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sizea = 0,a,ans=0;
char s[200000001];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s[sizea+j]=c;
        }
        sizea+=a;
    }
    int l=1;
    while(l<=(sizea+1)/2){
        if(s[l]!=s[sizea-l+1]) ans++;
        l++;
    }
    cout<<ans;
    return 0;
}
/*///
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sizea = 0,ans=0;
char s[200000001];
int a[200000001];
signed main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>s[i];
        sizea+=a[i];
    }
    int l=1;
    while(l<=(sizea+1)/2){
        if(s[l]!=s[sizea-l+1]) ans++;
        l++;
    }
    cout<<ans;
    return 0;
}
//*/