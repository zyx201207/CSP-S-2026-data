#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<long long>v;
long long ans;
void maopao(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(v[j]<v[j+1]){
				swap(v[j],v[j+1]);
			}
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		v.push_back(x);
		v.push_back(x);
	}
	maopao();
	if(m==1){
		cout<<v[0]<<endl;
		return 0;
	}
	ans=v[0]&v[1];
	if(m==2){
		cout<<ans<<endl;
		return 0;
	}
	for(int i=2;i<m;i++){
		ans=ans&v[i];
	}
	cout<<ans<<endl;
	
	return 0;
}
