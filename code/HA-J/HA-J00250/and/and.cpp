#include<bits/stdc++.h>
using namespace std;
vector<int> v[31];
int n,m,x,e[31]={1};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<=30;i++)e[i]=e[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		int l=1,r=30,mid=(l+r)/2;
		while(l<r){
			if(e[mid]<x)l=mid+1;
			else if(e[mid]>x)r=mid-1;
			else{
				v[mid].push_back(x);
				break;
			}
			mid=(l+r+1)/2;
		}
		if(l==r){
			if(x<e[l])v[l-1].push_back(x);
			else v[l].push_back(x);
		}
	}
	for(int i=30;i>=0;i--){
		if(v[i].size()>=m){
			sort(v[i].begin(),v[i].end());
			int ans=e[30]-1;
			for(int j=v[i].size()-1,k=1;k<=m;j--,k++){
				ans&=v[i][j];
			}
			cout<<ans;
			return 0;
		}
		else{
			for(int j=0;j<v[i].size();j++){
				x=v[i][j]-e[i];
				int l=1,r=30,mid=(l+r)/2;
				while(l<r){
					if(e[mid]<x)l=mid+1;
					else if(e[mid]>x)r=mid-1;
					else{
						v[mid].push_back(x);
						break;
					}
					mid=(l+r+1)/2;
				}
				if(l==r){
					if(x<e[l])v[l-1].push_back(x);
					else v[l].push_back(x);
				}
			}
		}
	}
	cout<<'0';
	return 0;
}
