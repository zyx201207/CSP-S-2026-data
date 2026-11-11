#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],sum;
string s[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=max(a[i],a[i-1]);
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<sum;
	}else{
		sum=a[n];
		for(int i=1;i<=m;i++){
			sum&=a[n-i+1];
		}
		cout<<sum;
	}
	return 0;
} 
