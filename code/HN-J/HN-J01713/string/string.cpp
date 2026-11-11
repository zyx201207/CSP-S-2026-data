#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const long long inf=1e13;
deque<pair<int,char> > q;
int n;
long long ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		q.push_back({a,c});
	}while(q.size()>=2){
		pair<int,char> bk=q.back();
		pair<int,char> ft=q.front();
//		cout<<q.size()<<' ';
		q.pop_front();
		q.pop_back();
//		cout<<ft.first<<' '<<ft.second<<' '<<bk.first<<' '<<bk.second<<' '<<ans<<"\n";
		if(bk.first>ft.first)
			if(bk.second==ft.second) q.push_back(make_pair(bk.first-ft.first,bk.second));
			else q.push_back(make_pair(bk.first-ft.first,bk.second)),ans+=ft.first;
		else
			if(bk.second==ft.second) q.push_front(make_pair(ft.first-bk.first,ft.second));
			else q.push_front(make_pair(ft.first-bk.first,ft.second)),ans+=bk.first;
		if(!q.empty()&&q.back().first==0) q.pop_back();
		if(!q.empty()&&q.front().first==0) q.pop_front();
	}cout<<ans;
	return 0;
}/*
2 a
2 b
1 c
ans=1

*/ 
