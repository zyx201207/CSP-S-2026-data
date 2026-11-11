#include<bits/stdc++.h>
using namespace std;
const int N=1e7+100;
long long n,r,cnt=0;
int p=0;
bool d=1;
string s="";
string a="",b="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;
        string a;
        cin>>m>>a;
        for(int j=0;j<m;j++){
            s+=a;
        }
    }
    if(s.size()%2==0){
        d=1;
    }
    else{
        d=0;
    }
    r=s.size()/2-1;
    for(int i=0;i<=r;i++){
        a+=s[i];
    }
    if(d==1){
        for(int i=r+1;i<s.size();i++){
            b+=s[i];
        }
    }
    else{
        for(int i=r+2;i<s.size();i++){
            b+=s[i];
        }
    }




    for(int i=0;i<=r;i++){
        if(a[i]==b[i]){
            cnt++;
        }
    }

    cout<<r-cnt+1;




    return 0;
}
