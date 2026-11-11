#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define int long long
//正解（我写不出来） 
//divide the array into two halfs,each element with a same length 
//with the oposite element in the other half（零点分段） 
//calculate the presum&postsum of two halfs to find differentiates
//（前后缀差异得回文不同） 

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len=0,cnt=0;
	cin>>n;
	string s=" ";
	for(int i=1; i<=n; i++)
	{
		int f; char c;
		cin>>f>>c;
		len+=f;
		for(int j=1; j<=f; j++) s+=c;
	}
	for(int i=1; i<=len/2; i++)
		if(s[i]!=s[len-i+1])
			cnt++;
	cout<<cnt<<endl;
	return 0;
}
