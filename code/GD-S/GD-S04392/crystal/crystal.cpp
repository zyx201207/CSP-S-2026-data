#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n;
long long m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	if(n == 1){
		cout<<1;
		return 0;
	}
	if(n == 2){
		long long x,y;
		cin>>x>>y;
		if(x > y){
			if(x-y > m) cout<<1;
			else cout<<2; 
		}else{
			if(y-x > m) cout<<1;
			else cout<<2; 
		}
		return 0;
	}
	for(int i = 1;i <= n;i++) cin>>a[i];
	priority_queue<long long,vector<long long>,greater<long long>> v;
	sort(a+1,a+n+1);
	long long w = 1,s = 1,c = m;
	v.push(a[1]);
	for(int i = 2;i <= n;i++){
		if(m - (a[i]-a[i-1])*s >= 0){
			m -= (a[i]-a[i-1])*s;
			s++;
			v.push(a[i]);
		}
		else{
//			cout<<a[i]-a[i-1]<<" ";
			if(a[i]-a[i-1] < a[i-1]-v.top()){
				m -= (a[i]-a[i-1])*s;
				m += a[i-1]-v.top();
				v.push(a[i]);
				v.pop();
			}else{
				while(!v.empty()) v.pop();
				if(s > 1){
					b[w] = s;
					s = 1;
					w++;
				}
				m = c;
				v.push(a[i]);
			}
		}
//		cout<<endl;
	}
	long long z = 1;
	for(int i = 1;i <= w;i++){
		if(b[i] > z) z = b[i];
	}
//	for(int i = 1;i <= z;i++){
//		long long z = v.top();
//		cout<<z<<" ";
//		v.pop();
//	}
//	cout<<endl;
	cout<<z;
	return 0;
}
