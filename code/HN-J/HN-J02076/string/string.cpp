#include<bits/stdc++.h>
using namespace std;
unsigned long long ans;
int n;
deque<int>qi;
deque<char>qc;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int i;
		char c;
		cin>>i>>c;
		qi.push_back(i),qc.push_back(c);
	}
	while(qi.size()>1){
		int f=qi.front(),b=qi.back();
		qi.pop_front(),qi.pop_back();
		char fc=qc.front(),bc=qc.back();
		qc.pop_front(),qc.pop_back();
		if(fc!=bc)ans+=min(f,b);
		if(f>b)qi.push_front(f-b),qc.push_front(fc);
		if(f<b)qi.push_back(b-f),qc.push_back(bc);
	}
	cout<<ans;
	return 0;
} 
/*
glider
.o.$o2.$3o!
*/
