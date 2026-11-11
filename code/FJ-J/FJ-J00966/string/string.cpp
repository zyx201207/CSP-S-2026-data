//CSP-J 2-string(OK)
#include<bits/stdc++.h>
using namespace std;
string s;
int n;
struct node{
	char c;
	long long x;
};
vector<node>v1,v2;
long long sum[200005];
long long tot;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		tot+=x;
		if(v1.size()&&c==v1.back().c)v1.back().x+=x;
		else v1.push_back({c,x}),cnt++;
	}
	v2=v1;
	reverse(v2.begin(),v2.end());
	sum[0]=v1[0].x;
	for(int i=1;i<cnt;i++){
		sum[i]=sum[i-1]+v1[i].x;
	}
	long long pos=(tot+1)/2;
	int t=cnt-1;
	for(int i=0;i<cnt;i++){
		if(sum[i]>=pos){
			t=i;
			break;
		}
	}
	int ans=min(pos-(sum[t-1]+1)+1,sum[t]-pos+1);
	cout<<(tot+1)/2-ans;
	return 0;
}
