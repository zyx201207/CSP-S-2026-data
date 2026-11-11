#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        string a(x,c);
        s+=a;
    }
    string l=s.substr(0,s.size()/2);
    string r=s.substr(s.size()/2+(s.size()%2),s.size()-1);
    //cout<<l<<endl<<r;
    reverse(r.begin(),r.end());
    int ans=0;
    for(int i=0;i<s.size()/2;i++){
        if(l[i]!=r[i]) ans++;
    }
    cout<<ans;
    return 0;
}
