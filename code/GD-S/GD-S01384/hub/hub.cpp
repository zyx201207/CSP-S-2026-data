#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int kd()
{
	char ca=getchar();
	bool fffff=true;
	int res=0;
	while(ca<'0'||ca>'9')
	{
		if(ca=='-') fffff=false;
		ca=getchar();
	}
	while(ca>='0'&&ca<='9') res=(res<<1)+(res<<3)+('0'^ca),ca=getchar();
	return (fffff?res:-res);
}
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	return 0;
}
