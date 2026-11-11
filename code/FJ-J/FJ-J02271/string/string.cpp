#include <bits/stdc++.h>
using namespace std;
struct qwe{
	long long n;
	string s;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		string a;
		cin>>a;
		for(int j=1;j<=m;j++){
			S+=a;
		}
	}
	int sz=S.size(),sum=0;
	for(int i=0;i<=sz/2;i++){
		if(S[i]!=S[sz-i-1]){
			sum++;
		}
	}
	cout<<sum;
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i].n>>a[i].s;
//	}
//	for(int i=1;i<=n/2;i++){
//		if(a[i].s!=a[n-i+1].s){
//			if(
//		}
//	}
	
	return 0;
}



