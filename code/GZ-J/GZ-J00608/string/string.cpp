//GZ-J00608 贵州师范大学附属中学 鲍翰宸 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	string S;
	int n,ans=0,m=0;
	cin>>n;
	vector<long long> a(n);
	vector<char> c(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(long long j=1;j<=a[i];j++)
		{
			S=S+c[i];
		}
		m+=a[i];
	}
	for(int i=0;i<(m/2);i++)
	{
		if(S[i]!=S[m-i-1]) ans++;
	}
	printf("%d",ans);
	return 0;
}
