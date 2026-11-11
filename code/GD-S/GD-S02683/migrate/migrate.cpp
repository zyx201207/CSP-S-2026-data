#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin >>c>>t;
	while(t--){
		int n ,d;
		int sum = 0;
		cin >> n>>d;
		long long a[555555] = {0};
		long long b[555555] = {0};
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		b[1]=0;
		for(int i =2;i<=n;i++){
			b[i] = a[i]-a[i-1]+b[i-1];
		}
		int f = 1;
		for(int i = 4;i<=n;i++){
			if((b[i]-b[i-2])<=d){
				sum += (i-f-2)*(n-i+1);
				f = i-2;
				for(int j = 1;j<f;j++){
					if((b[i-1]-b[j])>d&&(b[i-2]-b[j])<=d){
						sum-=j*(n-i+1);
					}
				}
			}
		}
		cout <<sum<<'\n';
	}
} 
