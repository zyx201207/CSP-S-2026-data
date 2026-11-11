#include <bits/stdc++.h>
using namespace std;

int n,m,ans=1;
const int N = 1e6+10;
long long sum = 0;
int a[N] = {0};
int main(){
	freopen('crystal.in','r',stdin);
	freopen('crystal.out','w',stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	long long avg=0;
	avg = sum/n;
	while(m>0){
		for(int i = 1;i <= n;i++){
			if(a[i] < avg && avg-a[i] <= m){
				a[i] == avg;
				if(a[i] >= 0){
					m = m-avg+a[i];
				}
				else{
					m = m-avg-a[i];
				}
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
