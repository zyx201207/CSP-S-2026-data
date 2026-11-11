#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int len;
	char val;
}s[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int alen=0;
	for(int i = 1;i<=n;i++){
		cin>>s[i].len>>s[i].val;
		alen+=s[i].len;
	}
	if(alen%2){
		int	mid=alen/2+1;
		vector<pair<int,char> > left;
		for(int i = 1,t=0;i<=n;i++){
			if(t+s[i].len>=mid){
				if(mid-t-1>0) left.push_back({mid-t-1,s[i].val});
				s[i].len-=mid-t;
				break;
			}
			left.push_back({s[i].len,s[i].val});
			t+=s[i].len;
		}
		int l = 0,r = n;
		int ans=0;
		while(l<left.size()){
			if(left[l].second!=s[r].val){
				ans+=min(left[l].first,s[r].len);
			}
			if(left[l].first>s[r].len){
				left[l].first-=s[r].len;
				s[r].len=0;
			}else{
				s[r].len-=left[l].first;
				left[l].first=0;
			}
			if(left[l].first==0) l++;
			if(s[r].len==0) r--;
		}
		cout<<ans<<endl;
	}else{
		int	mid=alen/2;
		vector<pair<int,char> > left;
		for(int i = 1,t=0;i<=n;i++){
			if(t+s[i].len>mid){
				if(mid-t>0) left.push_back({mid-t,s[i].val});
				s[i].len-=mid-t;
				break;
			}
			left.push_back({s[i].len,s[i].val});
			t+=s[i].len;
		}
		int l = 0,r = n;
		int ans=0;
		while(l<left.size()){
			if(left[l].second!=s[r].val){
				ans+=min(left[l].first,s[r].len);
			}
			if(left[l].first>s[r].len){
				left[l].first-=s[r].len;
				s[r].len=0;
			}else{
				s[r].len-=left[l].first;
				left[l].first=0;
			}
			if(left[l].first==0) l++;
			if(s[r].len==0) r--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
每年怎么都有一道字符串( 
while(1) rp++;
*/ 
