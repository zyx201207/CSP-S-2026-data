#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,sum=0,num=0;
	cin >> n;
	for (int i=1;i<=n;i++){
		int x;
		char y;
		cin >> x >> y;
		a[i]=x;
		c[i]=y;
		sum+=a[i];
	}
	if (sum<=1000000){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		for (int i=0,j=s.size()-1;i<=j;i++,j--){
			if (s[i]!=s[j]){
				num++;
			}
		}
		cout << num;
		return 0;
	}
	num=0;
	for (int i=1,j=n;i<=j;i++,j--){
		if (a[i]==a[j]){
			if (c[i]==c[j]){
				continue;
			}
			else {
				num+=a[j];
				continue;
			}
		}
		else {
			cout << "geile";
			return 0;
		}
	}
	cout << num;
	return 0;
} 
