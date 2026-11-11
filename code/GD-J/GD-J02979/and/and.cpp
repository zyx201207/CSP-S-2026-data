#include<bits/stdc++.h> 
using namespace std;
string s;
const int maxn=1e5+10;
int a[2*maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n;
	cin >> n;
	long long m;
	cin >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int maxx=-1;
	int b;
	for(int i = 1;i <= n;i++){
		b=a[i];
		for(int j = i;j <= n;j++){
			if(j==i+m)break;
			b&=a[j];
			maxx=max(maxx,b);
		}
	}
	cout << maxx;
	return 0;
}
