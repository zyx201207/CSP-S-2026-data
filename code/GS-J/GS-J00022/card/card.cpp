#include<iostream>
#include<vector>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
vector<int>v;
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		v.clear();
		for(int j=i;j<n;j++){
			for(int k=0;k<v.size();k++){
				if(v[k]==a[j]){
					for(int l=k;l<=v.size();l++)v.pop_back();
					break;
				}
			}
			v.push_back(a[j]);
		}
		for(int j=0;j<v.size();j++){
			cout<<v[i]<<' ';
			ans[j+1]++;
		}cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
