#include <bits/stdc++.h> 
using namespace std;

long long a[100010];
bool b[100010];

long long n,m;
long long f(long long m,long long i,long long ans){
	if(m==0){
		return ans;
	}
	long long cnt=0;
	for(int j=i+1;j<=n;j++){
		long long ans1=a[j]&ans;
		cnt=max(cnt,f(m-1,j,ans1));
	} 
	return cnt;
}

int main(){
	//ÊäÈë 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		long long ans=a[i];
		cnt=max(cnt,f(m-1,i,ans));
	}
	cout<<cnt;
}
