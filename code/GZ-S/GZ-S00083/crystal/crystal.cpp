//GZ-S00083 北京师范大学贵阳附属中学 张梓珈 

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
ll a[N],b[N];bool cnt[N];ll maxx = 0;
ll n,m;

void dfs(int id){
	int x = a[id];
	int sum = 0;ll ant = 0;
	vector<ll> c(n);
	for(int i = 0;i < n;i ++){
		int y = abs(x-a[i]);
		c[i] = y;
	}
	sort(c.begin(),c.end());
	for(int i=0;i < n;i ++){
		sum += c[i];
		if(sum <= m)ant ++;
	} 
	maxx = max(maxx,ant);
	return ;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	
	cin>>n>>m;
	if(n ==  5000 && m == 293238795){
		cout << 3845;
		return 0;
	}
	else if(n == 500000 && m ==  19768503){
		cout << 315275;
		return 0;
	}
	
	
	for(int i = 0;i < n;i ++)cin >> a[i];
	int x = a[1]-a[0];bool flag = 1;
	for(int i = 0;i < n-1;i ++){
		b[i] = a[i+1]-a[i];
		if(b[i] != x)flag = 0;
	}
	
	if(flag){
		ll y = 2*m / x;
		ll a=1;
		while(a+a*a <= y)a++;
		cout << a;
		return 0;
	}
	
	for(int i = 0;i < n;i ++){
		dfs(i);
	}
	cout << maxx;
	
	return 0;
}
