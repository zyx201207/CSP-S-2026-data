#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s,s2;
    long long n,sum=0,longans=0,maxans=0;
    while(n--){
        int a;
        string s1;
        cin>>a>>s1;
        while(a--){
            s=s+s1;
            s2=s1+s2;
        }
    }
    sum=s.size();
    for(int i=0;i<sum/2;i++){
        if(char(s[i])==char(s2[i])){
            longans++;
        }
        else{
            if(longans>=maxans)maxans=longans;
            longans=0;
        }
    }
    cout<<sum/2-maxans;
    return 0;
}
