#include <bits/stdc++.h>
using namespace std;
int n,a,s,g,f;
char d;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","W",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>s>>d;
    if(d=='a'){
        a+=s;
        g+=1;
    }
    else if(d!='a'){
        f+=s;
    }
}
if(g==n)
    cout<<0;
else if(f>=a)
    cout<<a;
else
    cout<<f;
return 0;
}
