#include <bits/stdc++.h>
using namespace std;

int ffind(vector<int> &o,int val){
	int p=0;
	for(int i:o){
		if(i==val){
			return p;
		}
		p++;
	}
	return -1;
}

int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	vector<int> desk;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int tmp=n;
	int cnt[m+1];
	fill(cnt,cnt+m+1,0);
	while(n--){
		for(int i=0; i<tmp; i++){
			int p=ffind(desk,a[i]);
			if(p>-1){
				desk.erase(desk.end()-p,desk.end());
			}
			desk.push_back(a[i]);	
		}
		for(int i:desk){
			cnt[i]++;
		}
	}
	for(int i=1; i<=m; i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
