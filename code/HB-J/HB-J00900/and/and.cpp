#include <bits/stdc++.h>
using namespace std;

long long a[200010],s[200010],b[200010];
bool vis[200010];
int n,m;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s[i]=s[i-1]+a[i];
	}
	
	if(m==1){
		sort(a+1,a+n+1);
		cout << a[n];
		return 0;
	}
	
	if(m==n){
		long long sum=a[1];
		for(int i = 2;i <= n;i++){
			sum=sum&a[i];
		}
		cout << sum;
		return 0;
	}
	
	if(m==2){
		long long sum=0;
		for(int i = 1;i <= n-1;i++){
			for(int j= i+1;j <= n;j++){
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout << sum;
		return 0;
	}
	int flag=1;
	for(int i = 2;i <= n;i++){
		if(a[i]!=a[i-1]){
			flag=0;
			break;
		}
	}
	if(flag){
		cout << a[1];
		return 0;
		}
	
	sort(a+1,a+n+1);
	long long sum=a[n-m+1];
	for(int i = n-m+1;i<=n;i++){
		sum=sum&a[i];
	}
	cout << sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
