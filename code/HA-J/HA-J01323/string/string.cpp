#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans,sum,op;
deque<long long>k;
deque<char>v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long q;
		char w;
		cin>>q>>w;
		if(k.size()==0){
			k.push_back(q);
			v.push_back(w);
			continue;
		}
		if(v[ans]==w){
			k[ans]+=q;
		}else{
			k.push_back(q);
			v.push_back(w);
			ans++;
		}
	}
	while(!k.empty()){
		if(v.front()==v.back()){
			if(k.front()>k.back()){
				op=k.front()-k.back();
				k.pop_front();
				k.pop_back();
				k.push_front(op);
				v.pop_back();
			}else if(k.front()<k.back()){
				op=k.back()-k.front();
				k.pop_front();
				k.pop_back();
				k.push_back(op);
				v.pop_front();
			}else{
				k.pop_back();
				k.pop_front();
				v.pop_back();
				v.pop_front();
			}
		}else{
			if(k.front()>k.back()){
				op=k.front()-k.back();
				sum+=op;
				k.pop_front();
				k.pop_back();
				k.push_front(op);
				v.pop_back();
			}else if(k.front()<k.back()){
				op=k.back()-k.front();
				sum+=op;
				k.pop_front();
				k.pop_back();
				k.push_back(op);
				v.pop_front();
			}else{
				sum+=k.front();
				k.pop_back();
				k.pop_front();
				v.pop_back();
				v.pop_front();
			}
		}
	}
	cout<<sum;
	return 0;
}
