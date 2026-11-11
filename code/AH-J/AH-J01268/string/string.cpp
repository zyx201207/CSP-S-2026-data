#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100010];
char c[100010];
string s;
int cnt=0;
int res=0;
bool huiwen(string s){
     string a="";
     int cnt=0;
     for(int i=s.size()-1;i>=0;i--){
        a[cnt]=s[i];
        cnt++;
     }
     for(int i=0;i<=cnt;i++){
        if(a[i]!=s[i])return 0;
     }
     return 1;
}
int main(){
     freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
     cin>>n;
     for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s[cnt]=c[i];
            cnt++;
        }
     }
          string a=s;
          reverse(a.begin(),a.end());
          for(int i=0;i<=s.size()-1;i++){
              s[i]=a[i];
              res++;
              if(huiwen(s)==1){
               cout<<res;
               break;
              }
          }
        return 0;
}
