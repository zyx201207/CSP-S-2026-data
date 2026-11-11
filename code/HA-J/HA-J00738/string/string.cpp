#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,a,m;
	long long int ans=0;
	char b;
	vector <char> s;
	vector <char> ss;
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	
    cin>>n;
    
    for(int i=1;i<=n;i++)
    { 
	    m=0;
    	cin>>a>>b;
    	//l+=a;
    for(int x=0;x<a;x++)
    {
     s.push_back(b) ;
    }
    }
    
    /*for(int i=0;i<s.size();i++)
    {
    	cout<<s[i];
    }*/
    //cout<<" "<<s.size() <<endl;
    /*for(int i=s.size();i<0;i--)
    {
    	ss.push_back(s[i]) ;
    }*/
    for(int i=0;i<s.size();i++)
    {
    	if(s[i]!=s[s.size()-1-i])
    	{
    	ans++;	
    	//cout<<i<<" "<<ans<<" ";
    	}
    }
    cout<<ans/2;
    
	return 0;
}
