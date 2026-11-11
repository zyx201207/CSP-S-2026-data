#include <bits/stdc++.h>
using namespace std;
string a;
string a2;
long long b[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0,cnt=0;
	cin >> n;
	for(int i=0;i<n;i++){
		long long c;
		cin >> c;
		cin >> a2[i];
		b[i]=c;
		ans+=c;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<b[i];j++){
			a+=a2[i];
		}
	}
	for(int i=0;i<ans;i++){
		if(a[i]!=a[ans-1-i])cnt++;
	}
	cout << cnt/2;
	return 0;
}
