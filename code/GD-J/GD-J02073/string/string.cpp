#include<bits/stdc++.h>
using namespace std;
int n;
int a[200001],b[200001];
char c[200001];
string s;
deque<pair<char,int>> q;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		q.push_back({c[i],a[i]});
	}	
	while(q.size()>1){
		pair<char,int> x=q.front(),y=q.back();
		q.pop_back(),q.pop_front();
		int x1=x.second,y1=y.second;
		if(x.first!=y.first){
			ans+=min(x1,y1);
		} 
		if(x1<y1)
			q.push_back({y.first,y1-x1});
		else if(x1>y1)
			q.push_front({x.first,x1-y1});
	}	
	cout<<ans;
	return 0;
}
