//ÀîéÈº­ GZ-J00046
#include<iostream>
#include<vector>
using namespace std;
int n,m,ans;
int a[200001];
vector<int> id,tmp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		id.push_back(i);
	}
	for(int i=29;i>=0;--i){
		for(int j:id){
			if((a[j]>>i)&1){
				tmp.push_back(j);
			}
		}
		if(tmp.size()>=m){
			id=tmp;
			ans+=(1<<i);
		}
		tmp.clear();
	}
	if(id.size()<m){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}
