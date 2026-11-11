#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        char a;
        cin>>a;
        for(int i=1;i<=x;i++){
            s+=a;
        }
    }//in
    string f,d;
    f=s;//aabbc
    //    cbbaa
    reverse(s.begin(),s.end());
    d=s;
    s=f;//reverse
    int g=1;
    long long cnt=0;
    long long len = d.size();
    for(long long i=0;i<s.size();i++){
        if(s[i]!=d[i]){
            if(i<=(len-i-1)){
                s[i]=d[len-i-1];
                //cout<<s[i]<<" "<<d[i]<<endl;
            }

            else {
                s[i]=d[i];
                //cout<<s[i]<<" "<<d[i]<<endl;
            }
        }
    }
    //cout<<s;
    //make huiwen
    for(long long i=0;i<s.size();i++){
        if(d[i]!=s[i]){
            cnt++;
            //cout<<d[i]<<" "<<endl;
            g=0;
        }
    }

    //cout<<s<<" "<<d<<endl<<endl;
    if(g) cout<<0;
    else cout<<cnt;
    return 0;
}
