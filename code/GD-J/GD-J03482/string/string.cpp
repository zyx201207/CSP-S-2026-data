#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200005],hs=0;
    string s,s1,sr;
    char sh[500005]={};
    int w[500005]={};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i]>>s[i];
    	w[i]=ceil(a[i]/2.0);
    	for(int j=1;j<=a[i];j++){
    		s1=s1+s[i];
		}
	}
	int j=0;
	for(int i=1;i<=s1.size();i++){
		sr=sr+s1[s1.size()-i];
	}
	if(sr==s1) cout<<0;
	for(int i=1;i<=n;i++)
	{
		while(w[i])
		{
			
			sh[i]=s[i];
			sh[s1.size()+1-i]=s[i];
			w[i]--;
		}
	}
	int d=-1;
	for(int i=1;i<=s1.size();i++)
	{
		if(s1[i]!=sh[i]) d++;
	}
	cout<<d;
	return 0;
}

