#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,g;
    int a[100],c[100];
    queue<int>q(100);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i]>>c[i];
		if(c[i]==q.front())
		{
			q.pop();
		}
		for(int j=1;j<=a[i];j++)
		{
			q.push(c[i]);
		}
    }
    if(q.empty())
    {
		cout<<"0";
	}
	else if(q.
    return 0;
    fclose(stdin);
    fclose(stdout);
}
