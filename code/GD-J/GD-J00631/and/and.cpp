#include<bits/stdc++.h>
using namespace std;
long long s[1000100];
int main(){
	
	freopen("and.in.txt","r",stdin);
	freopen("and.out.txt","w",stdout);
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++)scanf("%lld",&s[i]);
	sort(s+1,s+1+n);
	long long cnt=s[n];
	m--;
	for(int i=n-1;i>0;i--){
		if(m==0)break;
		cnt=(cnt&s[i]);
		m--;	
	}
	cout << cnt;
	
	return 0;
}
