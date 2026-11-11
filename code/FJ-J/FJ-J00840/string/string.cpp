#include<bits/stdc++.h>
#define pic pair<int,char>
using namespace std;
const int N=2e5+5;
unsigned long long n,cnt;
deque<pic>q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;char c;
		cin>>a>>c;
		q.push_back({a,c});
	}
	while(!q.empty()){
		pic l=q.front();
		q.pop_front();
		if(q.empty())break;
		pic r=q.back();
		q.pop_back();
		if(l.first==r.first){
			if(l.second!=r.second)cnt+=l.first;
		}else if(l.first>r.first){
			if(l.second!=r.second){
				cnt+=r.first;
				q.push_front({l.first-r.first,l.second});
			}else q.push_front({l.first-r.first,l.second});
		}else if(l.first<r.first){
			if(l.second!=r.second){
				cnt+=l.first;
				q.push_back({r.first-l.first,r.second});
			}else q.push_back({r.first-l.first,r.second});
		}
	}
	cout<<cnt<<'\n';
	return 0;
}

