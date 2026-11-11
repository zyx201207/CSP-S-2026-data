#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int n[505],i=1;
	char a[505];
	for(;i<=2;i++){
		cin>>n[i]>>a[i];
	}
	if(n[i]==n[i-1]){
		cout<<"1";
		if(a[i]/10==a[i-1]/10)
		{
			if(a[i]%10<'C'&&a[i-1]>'D')
			{
			cout<<"00";
			if(a[i]%10-a[i-1]%10==1||a[i]%10-a[i-1]%10==-1){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		else
		{
			cout<<"1";
			if(a[i]%10-a[i-1]%10==1||a[i]%10-a[i-1]%10==-1){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
	}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
