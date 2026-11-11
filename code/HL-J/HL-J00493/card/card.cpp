#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,m;cin >> n >> m;
	int nums[n+1];
	int res[n+1]={};
	for(int i=1;i<=n;i++){
		cin >> nums[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> a;
		for(int j=i;j<=n;j++){
			for(int c=0;c<a.size();c++){
				if(a[c]==nums[j]){
				// 	for(int x=c;x<a.size();x++)
				// 	{
						
				// 	}
					a.erase(a.at(c),a.end());
					break;
				}
			}
			a.push_back(nums[i]);
		}
		int thisr[m+1]={};
		for(int j=1;j<=a.size();j++){
			thisr[a[i-1]]=1;
		}
		for(int j=1;j<=m;j++){
			res[j]+=thisr[j];
		}
	}for(int i=1;i<=n+1;i++){
		cout << res[i] << " ";
	}
	return 0;
}
