#include<bits/stdc++.h>
using namespace std;
long long n,a;
char c;
queue<char> q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		x+=a;
		for(int j=0;j<a;j++){
			q.push(c);
		}
	}
	queue<char> q1;
	bool f=1;
	int ans=0;
	for(int i=0;i<x/2;i++){
		q1.push(q.front());
		if(q1.front()!=q.back()){
			f=0;
			ans++;
		}
		q.pop();
	}
	if(f==1) cout<<0;
	else cout<<ans;
	return 0;
}

