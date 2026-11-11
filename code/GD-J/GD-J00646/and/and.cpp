#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,k,cnt[35];
vector<int>val{};
inline bool cmp(int q,int p){return q>p;}
inline int check(int st){
	for(int i=st;i>=0;i--){
		int cnt=0;
		for(int x : val)if((x&(1<<i))==(1<<i))cnt+=1;
		if(cnt>=k)return i;
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//É¾×¢ÊÍ
	cin>>n>>k;
	for(int i=0,x;i<n;i++)cin>>x,val.emplace_back(x);
	int i=32,ans=0;i=check(i);
	
	while(i>=0){
		ans=(ans^(1<<i));
		for(int j=0;j<val.size();j++){
			if((val[j]&(1<<i))==0)val[j]=0;
		}
		sort(val.begin(),val.end(),cmp);
		for(int j=n-1;j>=0;j--){
			if(val[j]==0)val.pop_back();
		}
//		cout<<"-----"<<i<<"\n";
//		for(int x : val)cout<<x<<" ";cout<<'\n';
		i=check(i-1);
//		cout<<i<<"-----\n";
	}
	
	cout<<ans<<'\n';
	return 0;
} 
//4 2 3 15 12 12
//5 3 31 3 1 15 7
