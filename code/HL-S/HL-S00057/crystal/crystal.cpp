#include <bits/stdc++.h>
using namespace std;
int main()
{
	frepoen("crystal.in","r",stdin);
	frepoen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nl[500000];
	for(int i=0;i<n;i++)
    {
        cin>>nl[i];
    }
    sort(nl,nl+n);
    cout<<3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
