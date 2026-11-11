//GZ-J00193 个人报名 李青云
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int s[200005];
long long ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
	}
	sort(s+1,s+1+n);
	int h=s[n];
	for(int i=1;i<m;i++)
	{
	    h&=s[n-i];
	}
	cout<<h;

	return 0;
}
