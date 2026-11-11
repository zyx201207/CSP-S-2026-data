#include<bits/stdc++.h>
#define int int_fast64_t
using namespace std;
int a[int(5e5+5)],b[int(5e5+5)],t[int(5e5+5)],ans[int(5e5+5)];
vector<int> vec;
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		t[a[i]]++;
	}
	sort(b+1,b+n+1);
	bool f=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			f=1;
			break;
		}
	}
	if(!f){//A
		for(int i=1;i<=m;i++){
			t[i]+=t[i-1];
			cout<<t[i]<<' ';
		}
	}
	for(int i=1;i<=n;i++){
		vec.clear();
		for(int j=i;j<=n;j++){
			vec.push_back(a[j]);
			int f=0;
			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k])f=k;
			}
			if(f){
				for(int k=0;k<vec.size();k++){
					if(vec[k]==a[j]){
						vec.erase(vec.begin()+k,vec.end());
						vec.push_back(a[j]);
						break;
					}
				}
				j=f;
			}
		}
		for(auto it:vec)ans[it]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
