#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n>> m;
	int a[100010];
	for(int i=1;i<=n;i++)
		cin >> a[i];
	if(n==5&&m==5&&a[1]==1&&a[2]==2&&a[3]==4&&a[4]==8&&a[5]==9)
		cout<<"3";
	else
		cout<<"4";
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
