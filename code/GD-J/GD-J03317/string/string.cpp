#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,g,cnt=0,r=0,l=0;
	string s1,z;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>g>>z;
		for(int i=1;i<=g;i++)
			s1+=z;
	}
	
	r=s1.size();
	while(l<=r-l-1){
		if(s1[l]!=s1[r-l-1]) 
		{
			cnt++;
		}
		l++;
	}
	cout<<cnt;
	return 0;
}

