 #include<bits/stdc++.h>
 using namespace std;
 long long a[200005];
 char s[200005];
 int n;
 long long ans;
 int main(){
     freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
     cin>>n;
     int t=n;
     for(int i=1;i<=t;i++){
        cin>>a[i]>>s[i];
        if(s[i]==s[i-1]){
            a[i-1]+=a[i];
            i--;
            t--;
        }
     }
     for(int i=1;i<=n/2;i++){
        if(a[i]!=a[n+1-i]&&s[i]==s[n+1-i]){
            ans+=abs(a[i]-a[n+1-i]);
        }
        else if(a[i]==a[n+1-i]&&s[i]!=s[n+1-i]){
            ans+=a[i];
        }
        else if(a[i]!=a[n+1-i]&&s[i]!=s[n+1-i]){
            ans+=max(a[i],a[n+1-i]);
        }

     }
     cout<<ans;
     return 0;
 }