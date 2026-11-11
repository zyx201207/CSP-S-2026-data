#include<bits/stdc++.h>
using namespace std;
int sum[500005];
vector<int> v;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mm=1;
	while(mm<=n){
		for(int i=mm;i<=n;i++){
			if(int(v.size())==0) v.push_back(a[i]);
			else{
				int b=-1;
				for(int j=0;j<int(v.size());j++){
					if(v[j]==a[i]){
						b=j;
						break;
					}
				}
				if(b==-1) v.push_back(a[i]);
				else{
					for(int j=int(v.size())-1;j>=b;j--){
						v.pop_back();
					}
					v.push_back(a[i]);
				}
			}
		}
		int j=int(v.size());
		while(v.size()){
			sum[v[--j]]++;
			v.pop_back();
		}
		mm++;
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
