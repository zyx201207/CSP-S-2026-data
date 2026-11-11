#include<iostream>
#include<string>
using namespace std;
int n;
string s;
bool hw(string s){
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    int p=s.size()/2;
    if(s.size()%2==1){
        for(int i=p+1;i<s.size();i++){
            if(s[i]==s[s.size()-1-i]){
                p--;
            }
        }
    }
    cout<<p;
    return 0; 
}
