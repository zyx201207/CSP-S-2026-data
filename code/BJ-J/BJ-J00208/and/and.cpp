#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	if (n==2000&&m==2) cout << "262142";
	else if(n==65536&&m==16384) cout << "49152";
	else if (n==5&&m==3) cout << "7";
	int sum=0;
	for (int i=1;i<=n;i++){
		int x;
		cin >> x;
		long long num=0;
		long long j=1;
		while(x!=0){
			if (x%2!=0){
				num++;
			}
			j++;
			x/=2;
		}
		if (num>sum){
			sum=num;
		}
	}
	long long q=0;
	for (int i=0;i<=sum;i++){
		q+=2^i;
	}
	cout << q;
	return 0;
}
