#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a;
    char c;
    string abc="";
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            abc+=c;
        }
    }
    int abclen=abc.size();
    int aaa=abclen/2+abclen%2;
    string q=abc.substr(0,abclen/2);
    string w=abc.substr(aaa,abclen-aaa+1);
    reverse(w.begin(),w.end());
    int y=0;
    for(int i=0;i<q.size();i++){
        if(q[i]!=w[i]){
            y++;
        }
    }
    cout<<y;
    return 0;
}
