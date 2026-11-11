#include<bits/stdc++.h>
using namespace std;
long long a[200005];
vector<int> g[200005];
int n,m;
bool v[20005];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]and a[i]==a[i]){
				g[i].push_back(j);
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			
		}
	}
	return 0;
}
