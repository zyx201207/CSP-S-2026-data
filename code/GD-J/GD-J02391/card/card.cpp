#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int g[N];
bool search(vector<int> arr,int x){
	for(int i=0;i<arr.size();i++){
		if(arr[i]==x)return true;
	}
	return false;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> v;
		for(int j=i;j<=n;j++){
			if(!search(v,a[j])){
				v.push_back(a[j]);
			}else{
				int flag=0;
				for(int k=0;k<v.size();k++){
					if(v[k]==a[j])flag=1;
					if(flag==1){
						v.erase(v.begin()+k);
						k--;
					}
				}
				v.push_back(a[j]);
			}
		}
		for(int j=0;j<n;j++){
			if(search(v,j))g[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<g[i]<<' ';
	}
}
