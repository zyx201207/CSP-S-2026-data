#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
string c[1000005],s[10000005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n;
	cin >>n;
	long long k=0;
	for(int i=1;i<=n;i++){
		cin >> a[i]>> c[i];
		for(int j=1;j<=a[i];j++){
			k++;
			s[k]=c[i];
		}
	}
	long long cnt=0;
	for(int i=1;i<=k/2;i++){
		if(s[i] !=s[k-i+1]){
			cnt++;
		}
	}
	cout <<cnt;

	return 0;
}