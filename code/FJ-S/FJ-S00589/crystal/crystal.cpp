#include<bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long a[500005];
long long sum;
long long now_up;
long long o=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int now_up=a[1];
	while(m>=0){
		while(now_up==a[o]){
			o++;
			sum++;
		}
		m-=sum;
		now_up++;
	}
	cout<<sum;
	return 0;
}
