//GZ-J00681 陈先锐
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,sum=0;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)s+=c;
    }
    string s2=s;
    reverse(s2.begin(),s2.end());
    if(s2==s)cout<<sum;
    else{
        int i=s.size();
        while(i>=0){
            if(s[i]!=s2[i]){
                s[i]==s2[i];
                string s2=s;
                reverse(s2.begin(),s2.end());
                if(s2==s)cout<<sum;
            }
        }
    }
    return 0;
}
