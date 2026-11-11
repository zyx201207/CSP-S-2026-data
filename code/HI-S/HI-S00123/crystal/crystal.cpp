#include<bits/stdc++.h>
using namespace std;
long long a[500010];
queue<int> Q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>> n >> m;
	bool f1 = 1,f2 = 1;
	long long val = 0;
	for(int i = 1;i <= n;i++){
		cin>> a[i];
		if(a[i] != i){
			f1 = 0;
		}
		if(i >= 3){
		    if(!(a[i]-a[i-1] == a[i-1]-a[i-2])){
			    f2 = 0;
		    }
	    }
		val = a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	if(f1){
		int ans = 1,now = 1;
		while(1){
			if(m >= now){
				m -= now;
				ans++;
			}else{
				break;
			}
			now++;
			if(now >= n){
				break;
			}
		}
		cout<< ans;
		return 0;
	}
	if(f2){
		int ans = 1,now = 1;
		while(1){
			if(m >= now*val){
				m -= now*val;
				ans++;
			}else{
				break;
			}
			now++;
			if(now >= n){
				break;
			}
		}
		cout<< ans;
		return 0;
	}
	Q.push(1);
	int ans = 1;
	for(int i = 2;i <= n;i++){
		Q.push(i);
		m -= ((int)(Q.size())-1)*(a[i]-a[i-1]);
		while(m < 0){
			m += a[i]-a[Q.front()];
			Q.pop();
		}
		ans = max(ans,(int)(Q.size()));
	}
	cout<< ans;
	return 0;
}
