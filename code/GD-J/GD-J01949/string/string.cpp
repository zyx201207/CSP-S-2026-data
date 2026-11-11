#include<bits/stdc++.h>
using namespace std;
int n;
int x;
char y;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> x >> y;
		for (int j=1;j<=x;j++)
			a+=y;
	}
	long long sum=0;
	int A=a.size();
	if (A%2==0){
		for (int i=0;i<=A/2-1;i++){
			if (a[i]!=a[A-1-i]) sum++;
		}
	}
	else {
		if (A!=1)
		for (int i=0;i<=A/2-1;i++){
			if (a[i]!=a[A-1-i]) sum++;
		}
	}
	cout << sum;
	return 0;
} 
