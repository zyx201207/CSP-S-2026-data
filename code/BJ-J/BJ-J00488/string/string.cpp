#include<bits/stdc++.h>
using namespace std;
int a[100010];
long long cnt;
char c[100010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    string s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int t;
    if(s.size()%2==0){
        t=s.size()/2;
        string s1="",s2="";
        for(int i=0;i<t;i++){
            s1+=s[i];
        }
        for(int i=s.size()-1;i>=t;i--){
            s2+=s[i];
        }
        for(int i=0;i<t;i++){
            if(s1[i]!=s2[i]){
                cnt++;
            }
        }
    }else{
        t=s.size()/2;
        string s1="",s2="";
        for(int i=0;i<t;i++){
            s1+=s[i];
        }
        for(int i=s.size()-1;i>t;i--){
            s2+=s[i];
        }
        for(int i=0;i<t;i++){
            if(s1[i]!=s2[i]){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
