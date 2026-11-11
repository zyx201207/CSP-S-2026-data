#include <iostream>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x;
    string c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        cin>>c;
        for(int j=1;j<=x;j++){
            s+=c;
        }
    }
    int cnt=0;
    for(int i=1;i<=s.length()/2+1;i++){
        for(int j=s.length()/2+1;j>=1;j--){
            if(s[i]!=s[j]){
                s[j]=s[i];
                cnt++;
            }
        }
    }
    cout <<cnt;
}
