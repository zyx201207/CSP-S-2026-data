//GZ-J00125 习水县第七中学 李卓巾 

#include <bits/stdc++.h>
using namespace std;

int ans[10000];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,a[1000];
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++){
		vector<int> v;
		for(int j=i;j<=n;j++){
			for(int k=0;k<v.size();k++){
				if(v[k]==j){
					for(int a=k;a<v.size();a++)v.pop_back();
					break;
				}
			}
			v.push_back(j);
		}
		for(int j=0;j<v.size()-1;j++){
			ans[v[j]]++;
		}
		v.clear();
	}
	
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
