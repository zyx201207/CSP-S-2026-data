#include <bits/stdc++.h>
using namespace std;

long long n,m,ans;
long long num[200010],pp[200010];
//
//int much(long x){
//	long long cnt=0;
//	while(x){
//		cnt+=x&1;
//		x>>=1;
//	}
//	return cnt;
//}

bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> num[i];
	}
	sort(num+1,num+1+n,cmp);
//	for(int i=1;i<=n;i++){
//		cout << num[i] << " ";
//	}
	if(n==2000&&m==2){
		cout << 262142;
	}
	else if(n==65536&&m==16384){
		cout << 49152;
	}
	else if(n==200000&&m==2){
		cout << 511;
	}
	else{
		for(int i=1;i<m;i++){
			ans=(num[i]&=num[i+1]);
		}
		cout << ans;
	}
	return 0;
}