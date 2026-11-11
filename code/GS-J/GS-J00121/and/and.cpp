#include<bits/stdc++.h>
using namespace std;

int n,m,a[100005];
int main()
{
	//freopen("and","r",stdin);
	//freopen("and.out","w",stdout);
	
	cin >> n >> m;
	int unknow;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	
	
	for(int i = 1;i<= n;i++)
	{
		cout << a[i];
	}
	if(m==1){
		cout << a[1];
		return 0;}
	else
	{
		cout << unknow;
	}
	return 0;
}
