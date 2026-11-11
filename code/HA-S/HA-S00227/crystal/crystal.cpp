#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long N=5e5;
int n;
long long a[N];
long long m;
double sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	long long num=sum/n;
	long long t=1e12;
	int v=0;
	for(int i=1;i<=n;i++){
		int b=max(num,a[i]);
		int d=min(num,a[i]);
		if(t>b-d){
			t=b-d;
			v=i;
		}
	}
	for(long long i=1;i<=m;i++){
		if(a[i]<a[v]){
			while(a[i]<a[v]){
				a[i]++;
				m--;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[v]){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
