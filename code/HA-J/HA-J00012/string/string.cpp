#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    string s=" ";
    long long a;
    char c;
    cin >> n;
    for(long long i=1;i<=n;i++){
        cin >> a >> c;
        for(long long i=1;i<=a;i++){
            s += c;
        }   
    }
  //cout << s<<endl;
    long long l=s.size()-1;
    for(long long i=1;i<=l ;i++){
        if(s[i]!=s[l+1-i]) {
          //cout  <<s[l+1-i]<<" "<< s[i]<<endl;
            s[i]=s[l+1-i];
            ans++;
        }
    }
    cout <<ans;
    
	return 0;
}
