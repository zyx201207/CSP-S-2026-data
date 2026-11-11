#include<bits/stdc++.h>
using namespace std;
int a,b;
int w[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>w[i];
	}
	sort(w+1,w+a+1);
	int m=a/b;
	int n=m;
	int ans=w[1]&&w[a];
	for(int i=1;i<=b-2;i++)
	{
		ans==ans&&w[m];
		n+=m; 
	}
	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
