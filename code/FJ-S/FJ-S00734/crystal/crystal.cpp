#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long d[500005];
int ans = 1;

bool checkDc(){
	for(int i = 1;i < n;i++){
		d[i] = a[i+1]-a[i];
		if(d[i] != d[i-1]&&i >= 2) return false;
	}
	return true;
}
void dc(){
	int x = d[1];
	long long sum = 0;
	for(int i = 1;i < n;i++){
		sum = ((1+i)*i>>1)*x;
		if(sum > m){
			cout<<i<<endl;
			return ;
		}
	}
	cout<<n<<endl;
	return ;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
//	int t0 = time(0);
	
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+1+n);
	if(checkDc()){
		dc();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	for(int x = 1;x <= n;x++){
		for(int i = 1;i <= x;i++){
			d[i] = a[i]-a[x];
		}
		int sum = 0;
		long long mt = m;
		for(int i = x-1;i >= 1;i--){
			mt+=d[i];
			if(mt < 0) break;
			sum++;
		}
		int t = x;
		while(a[x+1] == a[x]){
			x++;
		}
		sum += x-t+1;
		ans = max(sum,ans);
	}
	
	cout<<ans;
//	cout<<time(0)-t0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
