#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
vector<char> s;
char a;
ll T,n,m;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>a;
       // s.clear();
        for(int i=1;i<=n;i++){
            s.push_back(a);

        }


    }
    if(s.size()%2==1){
          for(ll i=0,j=s.size()-1;i<s.size()/2&&j>=s.size()/2;i++,j--){
        if(s[i]!=s[j]){
            m++;
        }
    }
    }else{
    for(ll i=0,j=s.size()-1;i<s.size()/2&&j>=s.size()/2;i++,j--){
        if(s[i]!=s[j]){
            m++;

           }
    }
    }

        cout<<m;
    return 0;
}
/*
6
10 a
10 a
10 a
10 b
10 b
10 b
*/
