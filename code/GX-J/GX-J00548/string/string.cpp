#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int b;
    int n[100];
    string a[100];
    char pp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int pb[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cin>>b;
    for(int i=1;i<=b;i++){
        cin>>n[i];
        cin>>a[i];
    }
    string c="";

    for(int i=1;i<=b;i++){
        for(int j=1;j<=n[i];j++){
            c+=a[i];
        }
    }

    int aa=0;
    for(int i=0;i<c.size()-1;i++){
        if(c[i]!=c[i+1])break;
        aa++;
    }
    if(aa==c.size()-1)cout<<0;

    if(c.size()%2==0){
        int aaa=0;
        for(int i=0;i<c.size();i++){
            for(int j=0;j<26;j++){
                if(c[i]==pp[j]){
                    pb[j]++;
                }
            }
        }
        for(int y=0;y<26;y++){
            if(pb[y]==1)aaa++;
        }
        if(aaa==c.size())cout<<c.size();

    }








    return 0;
}
