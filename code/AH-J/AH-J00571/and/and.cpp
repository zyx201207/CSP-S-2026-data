#include<bits/stdc++.h>
using namespace std;
int n,m;
int and(int s,int b)
{
    vector<int>a(100);
    int ff;
    while(s!=0)
    {
		ff=s%2;
		a.push(ff);
		s=s/2;
	}
	return a;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int c[100];
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
		and(c[i],m);
		for(int j=2;j<=n;j++)
		{
			
	}
    return 0;
    fclose(stdin);
    fclose(stdout);
}
