#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<pair<int,char>>s;
	int n;
	long long ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		s.push_back({a,c});
	}
	pair<int,char>a,b;
	a.first=b.first=0;
	int p1=0,p2=n-1,t=0;
	while(p1<=p2)
	{
		t++;
		if(a.first==0)a=s[p1++];
		if(b.first==0)b=s[p2--];
		if(a.second==b.second)
		{
			//cout<<"T ";
			if(a.first>=b.first)
			{
				a.first=(a.first-b.first);
				b.first=0;
				//cout<<a.first<<' '<<b.first<<' ';
			}
			else
			{
				b.first=b.first-a.first;
				a.first=0;
				//cout<<a.first<<' '<<b.first<<' ';
			}
		}
		else
		{
			//cout<<"F ";
			if(a.first>=b.first)
			{
				ans+=b.first;
				a.first=a.first-b.first;
				b.first=0;
				//cout<<a.first<<' '<<b.first<<' ';
			}
			else
			{
				ans+=a.first;
				b.first=b.first-a.first;
				a.first=0;
				//cout<<a.first<<' '<<b.first<<' ';
			}
		}
		//cout<<ans<<' '<<t<<endl;;
	}
	cout<<ans;
	return 0;
}
