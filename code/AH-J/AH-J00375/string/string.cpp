#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int x,n;
    char a;
    cin>>n;
    if(n==1){
        cin>>x>>a;
        cout<<0;
        return 0;
    }
    string s="";
    for(int i=1;i<=n;i++){
        cin>>x;
        cin>>a;
        for(int j=1;j<=x;j++)s+=a;
    }
    int len=s.size();
    if(len%2==0){
        string s1=s.substr(0,len/2),s2=s.substr(len/2,len/2);
        int h=0;
        for(int i=0;i<len/2;i++){
            if(s1[i]!=s2[i]){
                h++;
            }
        }
        cout<<h;
    }else{
        string s1=s.substr(0,len/2),s2=s.substr((len+1)/2,len/2);
        int h=0;
        for(int i=0;i<len/2;i++){
            if(s1[i]!=s2[i]){
                h++;
            }
        }
        cout<<h;
    }
    return 0;
}
