#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int>v[31];
int a[N];
signed main(){
	//9:34切完前三道 
	//首先显然要贪心
	//其次有个很显然的结论
	//越高位的一越优
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<31;j++){
			if(a[i]&(1<<j))v[j].push_back(i);
		}
	}
	int fir=-1;
	//找第一个大小>=m的二进制位
	for(int j=30;j>=0;j--){
		if(v[j].size()>=m){
			fir=j;
			break;
		}
	} 
	if(fir==-1){
		cout<<0;
		return 0;
	}
	vector<int>t;//存当前要用的 
	t=v[fir]; 
	int ans=(1<<fir);
	while(1){
		for(int i=0;i<31;i++)v[i].clear();
		for(auto i:t){
			for(int j=0;j<31;j++){
				if(a[i]&(1<<j))v[j].push_back(i);
			}
		}
		int sec=-1;
		for(int j=fir-1;j>=0;j--){
			if(v[j].size()>=m){
				sec=j;
				break;
			}
		}	
		if(sec==-1){
			cout<<ans;
			return 0;
		}
		t=v[sec];
		ans+=(1<<sec);
		fir=sec;
	}
	cout<<ans;
	return 0;
}
