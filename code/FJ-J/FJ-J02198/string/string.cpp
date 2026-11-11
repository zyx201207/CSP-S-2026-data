#include<bits/stdc++.h>
using namespace std;
struct Node{
	int num;
	char c;
}cnt[500010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>cnt[i].num>>cnt[i].c;
		len+=cnt[i].num;
	}
	long long ans=0;
	deque <long long> q;
	q.push_back(1);
	q.push_back(n);
	while(!q.empty()){
		int fr=q.front();
		int ed=q.back();
		if(cnt[fr].num==cnt[ed].num){
			if(cnt[fr].c!=cnt[ed].c) ans+=cnt[fr].num;
			cnt[fr].num=0;
			cnt[ed].num=0;
			q.pop_front();
			q.pop_back();
			if(cnt[ed-1].num) q.push_back(ed-1);
			if(cnt[fr+1].num) q.push_front(fr+1);
		}
		else if(cnt[fr].num>cnt[ed].num){
			if(cnt[fr].c!=cnt[ed].c)ans+=cnt[ed].num;
			cnt[fr].num-=cnt[ed].num;
			cnt[ed].num=0;
			q.pop_back();
			if(cnt[ed-1].num) q.push_back(ed-1);
		}
		else if(cnt[fr].num<cnt[ed].num){
			if(cnt[fr].c!=cnt[ed].c) ans+=cnt[fr].num;
			cnt[ed].num-=cnt[fr].num;
			cnt[fr].num=0;
			q.pop_front();
			if(cnt[fr+1].num) q.push_front(fr+1);
		}
	}
	cout<<ans;
	return 0;
}
