#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int  a[100001];
	int  b[100001];
	int  y[100001];
	vector<int> v;
	int cut=0;
	long long n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];

	}
	sort(a,a+n);
	bool fx = true;
	for(int i = 1;i < n;i++){
		if(a[i] !=a[i-1]){
			fx = false ;
		}
	}
	if(fx == true){
		cout << "0";
		return 0;
	}
	int l = a[n/2];
	while(m--){
		for(int i = 0;i < n;i++){
			if(a[i] - l < 0){
				b[i] = l-a[i];
			}
			b[i] = l - a[i];
		}
		int sum = 0;
		for(int i = 1 ;i < n;i++){
			sum = 0;
			for(int s = 0;s < i ;s++){
				for(int j = s;j < i + 1;j++){
					sum += b[i];
				}
				if(sum == m){
					int z = i + 1 - s;
					v.push_back(z);
				}
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	cout << v[0];
	return 0;
}
