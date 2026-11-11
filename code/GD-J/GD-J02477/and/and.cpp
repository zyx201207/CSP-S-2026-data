#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int j=30;
	vector<int> v;
	for(;j>=0;j--){
		for(int i=1;i<=n;i++){
			if(a[i]&(1<<j)) v.push_back(a[i]);
		}
		if((int)v.size()>=m) break;
		v.clear();
	}
	if(j==-1){
		cout << 0;
		return 0;
	}
	int ans=(1<<j);
	j--;
	for(;j>=0;j--){
		vector<int> s;
		for(int i=0;i<(int)v.size();i++){
			if(v[i]&(1<<j)) s.push_back(v[i]);
		}
		if((int)s.size()>=m){
			v=s;
			ans+=(1<<j);
		}
	}
	printf("%d",ans);
	return 0;
}

