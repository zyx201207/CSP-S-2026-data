#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200010];
long long b[200010];
void print(){
	long long ans=a[1];
	for(long long i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=30;i>=0;i--){
		long long cnt=0;
		for(long long j=1;j<=n;j++){
			if(a[j]&(1<<i))cnt++;
		}
		if(cnt<m)continue;
		for(long long j=1,k=0;j<=n;j++){
			if(a[j]&(1<<i))a[++k]=a[j];
		}
		n=cnt;
	}
	print();
	return 0;
} 
