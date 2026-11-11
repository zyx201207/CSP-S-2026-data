#include<bits/stdc++.h>
using namespace std;
int n,m;
int Max;
bool vi[100005]={false};
int arr[100005];
int res[1000005];
//int Max;
void censhu(int st){
	if(st==m)
	{
		int s=res[0];
		for(int i=1;i<st;i++)
		{
			s=res[i]&s;
		}
		if(res[0]==res[1]) return ;
		Max=max(Max,s);
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(vi[i]==false)
		{
			vi[i]==true;
			res[st]=arr[i];
			censhu(st+1);
			vi[i]=false;
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	censhu(0);
	cout<<Max;
	return 0;
}
