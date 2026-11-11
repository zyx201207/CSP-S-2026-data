#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;
    long long m,z=0,c=0;
    string a="",s;
    //char s;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>m>>s;
        for(int j=1;j<=m;j++){
            a.append(s);
        }
        z+=m;
        //cout<<endl<<a;
    }

    string a1=a;reverse(a1.begin(),a1.end());
    if(a==a1){
        cout<<0;
    }else{
        cout<<z/2;
    }

    return 0;
}

