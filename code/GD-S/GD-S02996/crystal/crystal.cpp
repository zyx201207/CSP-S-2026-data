#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int mx=-1e9;
int a[500007];
vector<int>v[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){		
		for(int j=0;j<n;j++){
			for(long long num=0;num<=m;num++){
				if(a[j]+num==a[i]){
					v[i].push_back(num);
					continue;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<v[i].size();j++){
			sum+=v[i][j];
		}
		if(sum<=m){
			int size=v[i].size();
			mx=max(mx,size);
		}
	}
	cout<<mx;
	return 0;
} 
