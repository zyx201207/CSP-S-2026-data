//GZ-J00185 ³ÂÕıÁú
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int num[200005];
int maxv=0,cnt=1048575;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    for(;num[0]<n-m+1;)
    {
        num[m-1]++;
        for
        for(int i=m-1;i>0;i--)
        {
            if(num[i]>m)
            {
                num[i-1]++;
                num[i]=num[i-1]+1;
            }
        }

    }
	return 0;
}

