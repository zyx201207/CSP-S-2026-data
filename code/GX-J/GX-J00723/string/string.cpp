#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
char x;

string s,b;
bool r(string q){
    int len=q.size();
    bool v=1;
    for(int i=0;i<len;i++){

        if(q[i]!=q[len-1-i]){
            v=0;
        }

    }
    if(v==1) return 1;
    else return 0;
}
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>x;
        for(int i=1;i<=m;i++){
            s+=x;
        }
    }
    while(!r(s)){
        int len=s.size();
        s[len-1-ans]=s[ans];
        ans++;
    }
    cout<<ans;
}
