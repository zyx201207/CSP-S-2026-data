



#include <bits/stdc++.h>

using namespace std;
string s,c,r,l;
int main()
{   freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long n,a,f = 0;

    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a>>c;
        for(int i = 1;i<=a;i++)
            s+=c;

    }long long len = (s.size())/2;

    if((s.size())%2 == 1){
         f = 1;
    }


    for(int i = 0;i<len;i++){
        l += s[i];
    }for(int i = len+f;i<=s.size();i++){
        r += s[i];
    }
    long long sum = 0;
    for(int i = 0;i<len;i++){
        if(s[i] != s[len+f+1]){
            sum++;
        }

    }cout<<sum;

    return 0;
}


