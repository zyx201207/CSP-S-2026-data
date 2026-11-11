#include <bits/stdc++.h>
using namespace std;
int n,cnt[300003];
vector<int> a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int l;
		cin>>l;
		a.push_back(l);
	}
	for(int i=0;i<n;i++){
		vector<int> path;
		for(int j=i;j<n;j++){
			bool flag=false;
			path.push_back(a[j]);
			if(path.size()>1){
				int tempcnt=0;
				for(int k=j-1;k>=0;k--){
					tempcnt++;
					if(path[j]==path[k]){
						flag=true;
						break;
					}
				}
				if(flag) for(int k=0;k<tempcnt;k++) path.pop_back();
			}
		}
		for(int j=0;j<path.size();j++){
			cnt[path[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
} 
