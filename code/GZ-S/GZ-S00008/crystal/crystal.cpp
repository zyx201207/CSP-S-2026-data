#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+20;
long long n,m;
long long cnt,ma=-1;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(m==0){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	int k=a[n];
	while(n){
		for(long long i=1;i<=n;i++){
			cnt+=k-a[i];
			if(cnt==m){
				ma=max(ma,i);
			}
		}
		n--;
		k=a[n];
		cnt=0;
	}
	cout<<ma;
	return 0;	
}


