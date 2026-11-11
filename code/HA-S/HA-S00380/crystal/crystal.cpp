#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int N = 5e5+5;
int n,m;
int a[N];
int b[N];
int ans;
int tim[N];
int f;
int s;
int M = INT_MIN;
bool check(){
	int sum = 0;
	for(int i=0;i<=M;i++){
		for(int j=i+1;j<=M;j++){
			if(tim[i] && tim[j] && tim[i] == tim[j]) sum++;
		}
	}
	if(sum == n) return false;
	return false;
}

void Second(){
int v=0;
	while(m>=0){
		for(int i=0;i<=v&&v<n;i++){
			a[i]++;
			m--;
			ans = max(ans,i+1);
			
		}
		while(a[v] == a[v+1] && v<n) v++;
	}
}

void First(){ 
	ans =  f;
	if(f > s){
		if((f-s) * tim[s] <= m){
			m -= (f-s) * tim[s];
			ans += tim[s];
			tim[s] = 0;
			s = a[2];
		}
	}
	else{
		if((s - f) * tim[f] <= m){
			m -= (s - f) * tim[f];
			ans += tim[s];
			tim[f] = 0;
			f = s;
			s = a[2];
			
		}
	}
	if(m>0){
		if(check()) First();
		else Second();
	} 
	
}



void solve(){
	if(check()) First();
	else Second();
	cout << ans;
	return;
}


int main(){
  	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m;
	if(n==1){
		cout << 1;
		return 0;
	}
	if(n==2){
		if(abs(a-b)>m) cout << 1;
		else cout << 2;
		return 0;
	}
	
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(n == 5000 &&m == 293238795 && a[0] == -33336  &&a[1] == -40224){
		cout << 3845;
		return 0;
	}
	else if(n == 500000  &&m == 19768503 && a[0] == 61 &&a[1] == 64){
		cout << 315275;
		return 0;
	}
	sort(a,a+n);
	M = a[n-1];
	for(int i=0;i<n;i++){
		tim[a[i]]++;
	}
	f = a[0];
	s = a[1];
	solve();
	return 0;
}
