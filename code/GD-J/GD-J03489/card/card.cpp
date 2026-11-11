#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[510000];
long long ans[510000];
long long ans2[510000];
bool f=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans2[a[i]]++;
	}
	for(int i=2;i<=n&&f;i++){
		if(a[i]<a[i-1]){
			f=0;
		}
	}
	if(f){
		for(int i=2;i<=m;i++){
			ans2[i]+=ans2[i-1];
		}
		for(int i=1;i<=m;i++){
			cout<<ans2[i]<<' ';
		}
		return 0;
	}
	for(int t=1;t<=n;t++){
		vector<int>b;
		for(int i=t;i<=n;i++){
			bool f=1;
			for(int j=0;j<b.size()&&f;j++){
				if(b[j]==a[i]){
					f=0;
				}
			}
			if(f){
				b.push_back(a[i]);
			}else{
				vector<int>bb;
				for(int j=0;j<b.size();j++){
					if(b[j]==a[i]){
						break;
					}
					bb.push_back(b[j]);
				}
				bb.push_back(a[i]);
				b=bb;
			}
		}
		for(int i=0;i<b.size();i++){
			ans[b[i]]++;
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

