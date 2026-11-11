//68pts
#include<bits/stdc++.h>
using namespace std;
string s=" ";
int cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    double m=s.size()*1.0;
    for(int i=1;i<=ceil(m/2);i++){
        if(s[i]!=s[m-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
