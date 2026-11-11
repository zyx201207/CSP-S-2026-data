#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int i=0,l,a,b;
    vector<char>m;
    vector<int>s;
    cin>>i;
    for(int n=0;n<i;n++){
        cin>>s[n];
        cin>>m[n];
    }
    sort(m.begin(),m.end());
    if(m[0]==m[i])cout<<0;
    else{
        for(int j=0;j<i;j++){
            if(m[j]=='c')l++;
            if(m[j]=='a')a++;
            if(m[j]=='b')b++;
        }
        l+=a%b;
        cout<<l;
    }
    return 0;
}
