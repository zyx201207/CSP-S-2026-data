#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int num[200005];
int ans[100005];
map<int,int> M;
int n,m;
bool isA;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		M[num[i]]++;
		if(num[i]<num[i-1]) isA=1;
	}
	if(!isA){
		long long sum=n;
		for(int i=m;i>=1;i--){
			ans[i]=ans[i+1]+M[i];
		}
		for(int i=1;i<=m;i++){
			cout<<sum-ans[i+1]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		v.clear();
		for(int z=i;z<=n;z++){
			int a=num[z];
			for(int j=0;j<v.size();j++){
				if(v[j]==a){
					v.erase(v.begin()+j,v.end());
					break;
				}
			}
			v.push_back(a);
		}
		for(int j=0;j<v.size();j++) ans[v[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
