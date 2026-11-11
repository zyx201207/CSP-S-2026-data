#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N];
long long sum=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int i=1;
	while(m>-1){
		if(a[i]==a[i+1]){
			sum++;
			i++;
			continue;
		}
		m-=i;
		a[i]++;
	}
	cout<<sum;
	return 0;
}
