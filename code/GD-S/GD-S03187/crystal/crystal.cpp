#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,a[N];
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	bool flag=true;
	bool ff=true;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i){
			flag=false;
		}
	}
	sort(a+1,a+n+1);
	if(n==1){
		cout << 1;
		return 0;
	}
	if(flag){
		long long s=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i!=1){
				s=s+i-1;
			}
			if(s<=m){
				ans=i;
			}
			else{
				break;
			}
		}
		cout << ans;
		return 0;
	}

	long long k=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(k!=a[i]-a[i-1]){
			ff=false;
		}
	}
	if(ff){
		long long s=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			s=s+a[i]-a[1];
			if(s<=m){
				ans=i;
			}
			else{
				break;
			}
		}
		cout << ans;
		return 0;
	}
	priority_queue<long long,vector<long long>,greater<long long>> q;
	int ans=0;
	long long s=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				q.push(abs(a[j]-a[i]));
			}

		}
		int now=0;
		s=0;
		while(!q.empty()){
			if(s+q.top()<=m){
				s+=q.top();
				q.pop();
				now++;
			}
			else{
				break;
			}
		}
		ans=max(ans,now);
		while(!q.empty()){
			q.pop();
		}
	}
	ans++;
	cout << ans;
	
	return 0;
} 
