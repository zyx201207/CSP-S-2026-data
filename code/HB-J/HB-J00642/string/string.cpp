#include<bits/stdc++.h>
using namespace std;
string s;
char c[100000];
int n,m,x,y,a[100000],sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        x+=a[i];
        cin>>a[i]>>c[i];
        y+=a[i];
        for(int j=x;j<y;j++){
            s[j]=c[i];
        }      
    }
    m=(y-y%2)/2;
    for(int i=0,j=s.length();i<=m,j>m+1;i++,j--){
        if(s[i]!=s[j])sum+=1;
    }
    cout<<sum;
    freopen("string.out","w",stdout);
    freopen("string.in","w",stdout);
    return 0;
}