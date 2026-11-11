#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = 0;i < n-1;i++){
		b[i] = max(a[i],a[i+1])-min(a[i],a[i+1]);
	}
	for(int i = 0;i < n;i++){
		long long d = m,h = 0;
		bool e = true;
		for(int j = i;j < n-1;j++){
			if(d>0&&b[j]!=0&&e){
				d-=b[j]+c[i]*h;
				h=b[j];
				c[i]++;
			}else if(b[j] == 0&&e){
				c[i]++;
			}else{
				e = false;
				continue;
			}
		}
	}
	long long maxn = -1;
	for(int i = 0;i < n;i++){
		if(maxn < c[i]){
		maxn = c[i];
		}
	}
	cout << maxn << endl;
	return 0;
}
