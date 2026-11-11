 //GZ-S00122   付昕雨 绥阳县风华镇中心学校 
#include <bits/stdc++.h>
using namespace std; 
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	int n,m,a;
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++) 
	{
		if(m%a==0)
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
	}
	return 0; 
} 

