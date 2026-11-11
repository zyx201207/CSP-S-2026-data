#include <bits/stdc++.h>
using namespace std;
long long n;
long long a;
long long cnt,ans,num;
string c,s,s1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(long long j=1;j<=a;j++){
            s+=c;
            ans+=a;
        }
    }
    s1=s;
    reverse(s.begin(),s.end());
    if(s1==s){
        cout<<"0";
        return 0;
    }else{
        if(s.length()%2!=0){
            cnt=floor(s.length()/2);
            for(int i=1;i<=ans;i++){
                if(s1[i]!=s[i])
                    num++;
            }
            cnt=min(cnt,num);
        }
        else{
            cnt=s.length()/2;
            for(int i=1;i<=ans;i++){
                if(s1[i]!=s[i])
                    num++;
            }
            cnt=min(cnt,num);
        }
    }
    cout<<cnt;
    return 0;
}
