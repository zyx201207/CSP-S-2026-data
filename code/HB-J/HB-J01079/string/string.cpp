#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen(".in","r",stdin);
	freopen(".in","w",stdout);
	int n;
	cin >> n;
	int a[10010];
	char b[10010];
	for(int i=1;i<=n;i++)
		cin >>a[i]>>b[i];
	for(int i=1;i<=n;i++)
	{	if(b[i]==b[i+1])
			cout<<"0";
		
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
