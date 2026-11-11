#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int x;
    char a;
    string s="";
    for(int i=1;i<=n;i++){
        cin>>x>>a;
        if(x>=1000000){
            cout<<0;
            return 0;
        }
        for(int j=1;j<=x;j++){
            s=s+a;
        }
    }
    //cout<<s<<"\n";
    int l=s.size();
    int bl=l/2;
    if(l%2==1)bl=l/2+1;
    int bbl=l/2-1;
    int size1=bbl;
    int c=0;
    for(int i=bl;i<l;i++){
        if(s[i]!=s[bbl])c++;
        bbl--;
    }
    cout<<c;
    return 0;
}
