#include <iostream>
using namespace std;
	 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	int n,m,o=0,cnt=0,ant=0;
	cin >> n;
	string qcq;
	string a[100005];
	
	
	for(int i=0;i<n;i++)
{
		cin>>m>>qcq;
		o=m;
		ant+=m;
		for(int j=0;j<m;j++)
			a[o]=qcq;
}
	for(int i=0;i<=ant/2;i++)
	{
		
		if(a[i]!=a[ant-i])
			cnt++;
	}
	cout<<cnt;
	return 0;
	}

