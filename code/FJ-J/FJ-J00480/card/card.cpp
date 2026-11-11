#include<bits/stdc++.h>
using namespace std;
int a[514514];
bool b[514514];
int ans[514514];
int l[514514],r[514514];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
		for(int i=1;i<=n;i++){ 
			vector<int> v;
			memset(b,0,sizeof b);
			for(int j=i;j<=n;j++){
				for(int k=0;k<v.size();k++){
					if(b[k]==0&&v[k]==a[j]){
						for(int ii=k;ii<v.size();ii++){
							b[ii]=1;
						}
						break;
					}
				}
				v.push_back(a[j]);
			}
			for(int j=0;j<v.size();j++){
				if(b[j]){
					continue;
				}
				ans[v[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	else{
		bool bo=1;
		for(int i=2;i<=n;i++){
			if(a[i]<a[i-1]){
				bo=0;
				break;
			}
		}
		if(bo){
			for(int i=1;i<=n;i++){
				r[a[i]]=i; 
			}
			for(int i=1;i<=m;i++){
				cout<<r[i]<<" ";
			}
		} 
	}
}
/*
3 1 2 3 1 2
0 0 0 1 2 3
1 3
2 4
3 5
*/
