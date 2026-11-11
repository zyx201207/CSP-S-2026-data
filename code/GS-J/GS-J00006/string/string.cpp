#include <bits/stdc++.h>
using namespace std;
stack <char> a,m,w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 	long long n,c,t=0;
	char b;
	cin>>n;
	for(long long i=t;i<n;i++){
		cin>>c;
		cin>>b;
		for(long long j=0;j<c;j++){
			a.push(b);
			w.push(b);
		}
		t+=c;
	}
	for(long long i=0;i<t;i++){
		m.push(w.top());
		w.pop();
	}
	long long o=0;
	for(long long i=0;i<t;i++){
		cout<<m.top();
		cout<<a.top();
		
		if(m.top()==a.top())o=o;
		else o++;
		m.pop();
		a.pop();

	}	
	cout<<o/2;
	return 0;
}
