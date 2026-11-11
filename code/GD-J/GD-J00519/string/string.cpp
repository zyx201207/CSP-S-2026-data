#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int a1=0;
	char s;
}a[500009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].a1>>a[i].s;
	}
	int ant=n;
	int i=0;
	int j=n-1;
	long long sum=0;
	while(ant>1)
	{
		
		if(a[i].a1>a[j].a1)
		{
			j--;
			a[i].a1-=a[j].a1;
			ant--;
			if(a[i].s!=a[j].s)sum+=a[j].a1;
		}
		else if(a[i].a1<a[j].s)
		{
			i++;
			a[j].a1-=a[i].a1;
			ant--;
			if(a[i].s!=a[j].s)sum+=a[i].a1;
		}
		else {
			ant-=2;
			i++;
			j--;
			if(a[i].s!=a[j].s)sum+=a[i].a1;
		}
	}
	cout<<sum;
	return 0;
}
