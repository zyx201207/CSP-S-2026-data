#include<bits/stdc++.h>
using namespace std;
const int N=100001;
long long k,ans=0,cnt=0;
long long he=0;
char c;
string s="";
int main(){
     freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
     ios::sync_with_stdio();
     long long n;
     cin>>n;
     for(int i=0;i<n;i++){
        cin>>k>>c;
        for(int i=0;i<k;i++){
            s=s+c;
        }
        he=he+k;
     }
     string m=s;
     reverse(s.begin(),s.end());
     for(int i=s.size()/2;i<s.size();i++){
        if(s[i]==m[i]){
            cnt++;
        }
     }
     if(m==s){
        cout<<ans;
     }else{
         ans=(he+1)/2-cnt;
         cout<<ans;
     }
     return 0;
}
//Trick||Treat!
