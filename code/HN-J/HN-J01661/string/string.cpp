#include<bits/stdc++.h> 
using namespace std;
struct s
{
	long long a;
	char c;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,k=0;
	cin>>n;
	vector<s> b(n);
	string a;
	for(int i=0;i<n;i++)
	{
		cin>>b[i].a>>b[i].c;
		a.insert(a.size(),b[i].a,b[i].c);
	}
	for(int i=0;i<a.size()/2;i++)
	{
		if(a[i]!=a[a.size()-1-i]) k++;
	}
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
