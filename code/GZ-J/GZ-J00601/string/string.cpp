#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a;
	cin>>a;
	int n;
	char m[100005];
	for(int i=0;i<=a;i++){
		cin>>n;
		cin>>m;
		
	}
	for(int i=0;i<a;i++)
	{
		char  aa=m[i];
		if(aa==m[i-1])
		{
			cout<<"0";
		}
	}
	
	
	return 0;
}

