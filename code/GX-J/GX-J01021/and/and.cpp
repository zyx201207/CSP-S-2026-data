#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;


int ans,sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>ans>>sum;
	if(ans<sum)
	cout<<ans;
	if(ans>sum)
	cout<<sum;
	return 0;
}
