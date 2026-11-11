#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,b[N],ans[N];
vector<int>a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int ls;
		cin>>ls;
		b[i]=ls; 
	}
	int t=n;
	while(t--){
		while(a.size())a.pop_back();
		for(int i=t;i<=n;i++){
			bool flag=0;
			for(int j=0;j<n;j--){
				if(a[j]==b[i]){
					flag=1;
					break;
				}
			}
			if(flag){
				while(a.back()!=i)a.pop_back();
				a.pop_back();
			}
			a.push_back(i);
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<a.size();j++){
				if(a[j]==i){
					ans[i]++;
					break;
				}
			}	
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

