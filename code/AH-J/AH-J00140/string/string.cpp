#include<bits/stdc++.h>
using namespace std;
string s,s_;
char ci;
long long n,ai,sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ai>>ci;
        while(ai!=0)
        {
            s+=ci;
            s_+=ci;
            ai--;
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(!(s[s.size()-i-1]==s_[i])) sum++;
    }
    sum/=2;
    cout<<sum;
    return 0;
}
