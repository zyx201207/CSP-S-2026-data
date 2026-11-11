#include<bits/stdc++.h>
using namespace std;
long long n,l=0,ans=0,i,j;

vector<char> c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    char a[n][2];
    for(i=0;i<n;i++){
        for(j=0;j<2;j++){
            cin>>a[i][j];
            if(j==0) l=l+(long long)a[i][j]-48;
        }
    }
    for(i=0;i<n;i++){
        for(j=1;j<=(long long)a[i][0]-48;j++){
            c.push_back(a[i][1]);
        }
    }
    for(i=l/2+1;i<l;i++){
            if(c[i]!=c[l-1-i]) ans++;
        }
        cout<<ans;
    return 0;
}

