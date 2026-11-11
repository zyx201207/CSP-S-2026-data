#include<bits/stdc++.h>
using namespace std;
long long a[500020],b[500020]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cot = 1000000000;
	int x1 = 1,x2 = 1;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i] != i){
			x1 = 0;
		}
		
	}
	if(x1){
		long long sb = 0;
		for(int i = 1;i<=n;i++){
			sb += a[i];
			if(sb>m){
				cout<<i;
				return 0;
			}
		}
	}
	sort(a,a+n+1);
	int x3 = 0;
	for(int i = 2;i<=n;i++){
		if(a[i] - a[i]-1 != a[i+1]-a[i]){
			x2 = 0;
			break;
		}
	}
	for(int i = 1;i<=n;i++){
		cout << a[i];
	}
	if(x2){
		long long sb = 0;
		for(int i = 1;i<=n;i++){
			if(a[i] == 0){
				continue;
			}
			x3+=1;
			sb += a[i];
			if(sb>m){
				cout<<x3;
				return 0;
			}
		}
	}
	for(int i = 2;i<=n;i++){
		b[i] = a[i]-a[i-1];
	}
	for(int i = 1;i<=n;i++){
		long long s1 = i+1,s = 0;
		while(s1<n){
			s += (s1-i)*b[s1];
			if(s>m){
				break;
			}
			s1+=1;
		}
		cot = max(cot,s1-i);
	}
	cout<<cot;
	return 0;
}
