#include<bits/stdc++.h>
using namespace std;
vector<int>v[33];
int vs[500005];
int a[500005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int an=(1<<31)-1;
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<31;j++){
			if(a[i]&(1<<j)){
				v[j].push_back(i);
			}
		}
	}
	int no=0;
	for(int i=31;i>-1;i--){
		if(v[i].size()<m){
			continue;
		}else{
			no++;
			for(int j:v[i]){
				vs[j]++;
			}
			int c=0;
			for(int j=1;j<=n;j++){
				if(vs[j]==no){
					c++;
				}
			}
			if(c<m){
				no--;
				for(int j:v[i]){
					vs[j]--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vs[i]==no){
			an&=a[i];
		}
	}
	cout << an;
	return 0;
}
