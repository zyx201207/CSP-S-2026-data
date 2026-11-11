#include<bits/stdc++.h>
using namespace std;
int arr[200000];
bool arr2[200000];
int arr3[200000];
vector<pair<int,int>> vec;
int main(void)
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		if(arr2[arr[i]]==0)vec.push_back({arr[i],0}),arr2[arr[i]]=1;
		if(vec.size()==m)break;
	}
	// for(auto i:vec)cout<<i.first<<i.second<<endl;
	// cout<<endl;
	for(int i=0;i<n;i++)
	{
		string pai;
		for(int j=i;j<n;j++)
		{
			int fnd=pai.find(arr[j]);
			if(fnd!=string::npos)pai.erase(pai.begin()+fnd,pai.end());
			pai+=arr[j];
		}
		// VER 1
		// for(auto &j:vec)
		// {
		// 	if(pai.find(j.first)!=string::npos)(j.second)++;
		// }

		// VER2
		for(int i=1;i<=m;i++)
		{
			if(pai.find(i)!=string::npos)arr3[i]++;
		}
	}
	// VER1
	// for(auto i:vec)
	// 	cout<<i.second<<' ';

	// VER2
	for(int i=1;i<=m;i++)cout<<arr3[i]<<' ';
	return 0;
}
