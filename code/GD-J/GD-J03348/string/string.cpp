#include<iostream>
#include<deque>
using namespace std;
int n;
long long ans;
deque<long long> dq;
deque<char> cl;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;char c;
		cin>>x>>c;
		dq.push_front(x);
		cl.push_front(c);
	}
	while(dq.size()>1){
		long long lenA=dq.front(),lenB=dq.back();
		dq.pop_front();
		dq.pop_back();
		char cA=cl.front(),cB=cl.back();
		cl.pop_front();
		cl.pop_back();
		if(cA!=cB)ans+=min(lenA,lenB);
		if(lenA==lenB)continue;
		else if(lenA<lenB){
			dq.push_back(lenB-lenA);
			cl.push_back(cB);
		}
		else if(lenA>lenB){
			dq.push_front(lenA-lenB);
			cl.push_front(cA);
		}
	}
	cout<<ans;
	return 0;
} 
