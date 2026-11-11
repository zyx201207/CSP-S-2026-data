#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,sum=0;
	cin>>n;
	deque<int> nn(n,0);
	deque<char> nc(n);
	for(int i=0;i<n;i++){
		cin>>nn[i]>>nc[i];
	}
	while(nn.size()>1){
		if(nc[0]!=nc[nn.size()-1]){
			sum+=min(nn[0],nn[nn.size()-1]);
		}
		if(nn[0]<nn[nn.size()-1]){
			nn[nn.size()-1]-=nn[0];
			nn.pop_front();
			nc.pop_front();
		}else if(nn[0]==nn[nn.size()-1]){
			nn.pop_front();
			nc.pop_front();
			nn.pop_back();
			nc.pop_back();
		}else{
			nn[0]-=nn[nn.size()-1];
			nn.pop_back();
			nc.pop_back();
		}
	}
	cout<<sum;
	return 0;
}