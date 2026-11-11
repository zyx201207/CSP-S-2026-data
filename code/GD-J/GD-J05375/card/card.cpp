#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; cin >> n >> m;
	int arr[500010],ans[300010];
	for(int i=1;i<=m;i++){
		ans[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	for(int i=1;i<=n;i++){
		vector<int>q;
		for(int j=i;j<=n;j++){
			bool f=1;
			int x=-1;
			for(int k=0;k<q.size();k++){
				if(q.at(k)==arr[j]) f=0,x=k;
			}
			if(f) q.push_back(arr[j]);
			else{
				while(q.size()>=x+2){
					q.pop_back();
				}
			}
		}
		while(q.size()){
			ans[q.back()]++;
			q.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	
	
	
	return 0;
}
