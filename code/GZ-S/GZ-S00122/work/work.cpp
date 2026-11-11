//GZ-S00122   付昕雨 绥阳县风华镇中心学校 
#include <bits/stdc++.h>
using namespace std; 
int main(){
	freopen("work.in","r",stdin);
	freopen("work.out","w",stdout)
	int a,b;
	cin>>a>>b;
	if(a+b==0&&a%b==1)
	{
		cout<<"1"<<endl;
	}
	if(a*b==0)
	{
		cout<<"2"<<endl;
	}
	else
	{
		cout<<"3"<<endl;
	}
	return 0; 
} 
 
