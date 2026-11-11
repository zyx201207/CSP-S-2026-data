//GZ-J00209 遵义四中  邱果 
#include <bits/stdc++.h>
using namespace std;
long long l,r=23,len,n,len_cnt=-1,sum;
string s,a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while (n--)
	{
		cin>>len>>a;
		len_cnt+=len;
		for(int i=1;i<=len;i++)
		{
			s+=a;
		}}
	
	
	while (l<=r)
	{
		r=len_cnt-l;
		if (s[l]!=s[r])
		{
			sum++;
		}l++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

