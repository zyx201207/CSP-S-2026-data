#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n,m,ans,b[200005],tot;
vector<int> a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(auto j:a){
			if(j&(1<<i)){
				cnt++;
				b[++tot]=j;
			}
		}
		if(cnt>=m){
			ans+=(1<<i);
			a.clear();
			for(int i=1;i<=tot;i++)a.push_back(b[i]);
			tot=0;
		}
	}
	cout<<ans;
	return 0;
}
