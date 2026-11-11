#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long num;
	char s;
};
long long n,ans;
deque <Node> q;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	//cout<<q.size()<<endl;
	for(int i=1;i<=n;i++){
		int a;
		char sss;
		cin>>a>>sss;
		q.push_back({a,sss});
	}
	while(q.size()){
		int num_ber=q.front().num;
		int num_ber2=q.back().num;
		char ss=q.front().s;
		char ss1=q.back().s;
		q.pop_back();
		if(q.size()!=0){
			q.pop_front();
		}
		int numm=abs(num_ber-num_ber2);
		if(ss!=ss1){
			ans+=min(num_ber,num_ber2);
		}
		if(num_ber>num_ber2){
			q.push_front({numm,ss});
		}
		else if(numm!=0){
			q.push_back({numm,ss1});
		}
	}
	cout<<ans;
	return 0;
}