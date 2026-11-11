#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long N=2e5+10;
long long n,sum=0,cnt=0,ans=0,L=1,R=n;
vector<long long> num(N,0),a(N,0);
vector<char> ch(N,'0');
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	R=n;
	for(long long i=1;i<=n;i++) cin>>num[i]>>ch[i];
	for(long long i=1;i<=n;i++) sum+=num[i];
	long long mid=sum/2;
	while(L!=R)
	{
		long long k=min(num[L],num[R]);
		if(ch[L]!=ch[R]) ans+=k;
		if(num[L]<num[R]) L++,num[R]=num[R]-k;
		else R--,num[L]=num[L]-k;
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
