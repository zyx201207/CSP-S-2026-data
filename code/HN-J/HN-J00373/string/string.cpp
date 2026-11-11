#include <bits/stdc++.h>
using namespace std; 
long long a,cnt=0,c,mid;
char b;
string s,d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;	
		d+=b;
		while(a--)
			s+=b;
	}
	c=s.size();
	if(c%2==1){
		for(int j=c-1,k=0;j>=0;j--,k++){
			if(s[j]!=s[k]&&j!=k) cnt++;
			if(j==k)
			{
				cout << cnt;
				return 0;
			}
		}
	}		 
 	else
 	{
	 	for(int j=c-1,k=0;j>=0;j--,k++){
				if(s[j]!=s[k]&&j+1!=k-1) cnt++;
				if(j+1==k-1)
				{
					cout << cnt;
				}
			}
	}	
	return 0;
}
