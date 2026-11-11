#include<bits/stdc++.h>
using namespace std;
int a[200002];
char c[200002];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    string s;
    cin>>n;
    if(n<50000)
    {
    	for(int i=1;i<=n;i++)
    	{
        	char d;
        	int b;
        	cin>>b>>d;
        	while(b--) s+=d;
    	}
    //cout<<s<<'\n';
    //cout<<s.size()<<'\n';
    	for(int i=0;i<s.size()/2;i++)
    	{
        //cout<<"i:"<<i<<'\n';
    	    if(s[i]!=s[s.size()-i-1])
    	        ans++;//cout<<s[i]<<' '<<s[s.size()-i-1]<<'\n';
    	}
    	cout<<ans;

    	return 0;
	}
    else
    {
    	for(int i=1;i<=n;i++)
    	{
        	cin>>a[i]>>c[i];
    	}
    //cout<<s<<'\n';
    //cout<<s.size()<<'\n';
    	for(int i=1;i<=n/2;)
    	{
        	//cout<<"i:"<<i<<'\n';
        	int minn=min(a[i],a[n-i+1]);
        	if(c[i]!=c[n-i+1]) ans+=minn;
        	a[n-i+1]-=minn,a[i]-=minn;
        	if(a[i]==0)
            	i++;
        	if(a[n-i+1]==0)
            	n--;
    	}
    	cout<<ans;
		return 0;
	}
	return 0;
    /*
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n,ans=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    //cout<<s<<'\n';
    //cout<<s.size()<<'\n';
    for(int i=1;i<=n;)
    {

        int x=min(a[i],a[n-i+1]);
        cout<<"i:"<<i<<"  n:"<<n<<"  x:"<<x<<'\n';
        if(c[i]!=c[n-i+1])ans+=x;
        a[i]-=x,a[n-i+1]-=x;
        cout<<a[i]<<' '<<a[n-i+1]<<'\n';
        if(a[i]==0) i++;
        else n--;
    }
    cout<<ans;

    return 0;
    */
}
