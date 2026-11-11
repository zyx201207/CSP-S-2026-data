#include <bits/stdc++.h>
using namespace std;
string s,b[100005],s1;
int a[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            s.append(b[i]);
        }
    }

    for(int i=0;i<s.size();i++){
        s1+=s[(s.size()-i)];
    }
    s1+=s[1];

    if(s==s1){
        cout<<0;
        return 0;
    }
    else if(s1!=s){
        for(int j=0;j<s.size();j++){
            if(s[j]!=s1[j]) {
                s[j]=s[(s.size()-j-1)];
                if(s1!=s) cnt+=1;
                for(int i=0;i<s.size();i++){
                    s1+=s[(s.size()-i)];
                }
                s1+=s[1];
            }
            else break;
        }
    }

    cout<<cnt;
    return 0;
}

