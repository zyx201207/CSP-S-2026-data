#include<bits/stdc++.h>
using namespace std;
string s,rev_s;
#define ll long long
struct lls{
	ll num;
	char c;
};//ccf保佑我不报零！！！！！！！！！！！ 
ll n,a,cnt=0;
lls st[200005]={};
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>st[i].num>>st[i].c;
	}ll l=0,r=n,p=0;
	while(l<r){
		if(st[l].c==st[r].c){
			ll minn=min(st[l].num,st[r].num);
			st[l].num-=minn;st[r].num-=minn;
			if(st[l].num==0) l++;
			if(st[r].num==0) r--;
		} else{
			ll minn=min(st[l].num,st[r].num);
			st[l].num-=minn;st[r].num-=minn;
			if(st[l].num==0) l++;
			if(st[r].num==0) r--;
			cnt+=minn;
		}
	}cout<<cnt;
	return 0;
}
