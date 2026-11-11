#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a[200011];
char c[200011];
ll ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	deque<array<int,2>> q;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		q.push_back({a[i],c[i]-'a'});
	}
	while(q.size()>1){
		array<int,2> l,r;
		l=q.front();
		r=q.back();
		q.pop_front();
		q.pop_back();
		if(l[0]==r[0]){
			if(l[1]!=r[1]) ans+=l[0];
		}else if(l[0]>r[0]){
			if(l[1]!=r[1]) ans+=r[0];
			q.push_front({l[0]-r[0],l[1]});
		}else{
			if(l[1]!=r[1]) ans+=l[0];
			q.push_back({r[0]-l[0],r[1]});
		}
	}
	cout << ans;
	return 0;
}

