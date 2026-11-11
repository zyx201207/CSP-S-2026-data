//GZ-J00193 个人报名 李青云
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long s[100000005],sum1,sum2;
long long ans[30];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
	    int a;
	    char c;
	    cin>>a>>c;
	    s[sum1]+=(c-'a'+1)*1LL;
	    sum1+=a;
	    s[sum1]-=(c-'a'+1)*1LL;
	}
	for(int i=1;i<sum1;i++)
    {
	    s[i]=s[i-1]+s[i];
	}
	for(int i=0;i<sum1;i++)
    {
	    ans[s[i]]++;
	}
	for(int i=0;i<=28;i++)
	{
	    sum2=max(ans[i],sum2)*1LL;
	}
	cout<<sum1-sum2;
	
    return 0;
}


