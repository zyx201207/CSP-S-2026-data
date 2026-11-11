#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int ttl;
        cin>>ttl;
        string ls;
        cin>>ls;
        for(int j=1;j<=ttl;j++)
        {
            s=s+ls;
        }
    }
    int cnt=0;
    int j=0;
    for(int i=0;i<=s.length();i++)
    {
        
        j++;
        if(s[i]==s[s.length()-i])
        {
			continue;
        }
        else{
        	s[i]=s[j];
        	cnt++;
		}
        
        
    }
 
 	cout<<cnt-2;
    return 0;
}
