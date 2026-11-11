#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,maxv=0;
long long q[N];


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool f1=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> q[i];
		if(q[i]!=i-1){
			f1=0;
		}
	}
	
	if(m==1){
		for(int i=1;i<=n;i++){
			maxv=max(maxv,q[i]);
		}
		cout << maxv;
	}
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxv=max(maxv,q[i]&q[j]);
			}
		}
		cout << maxv;
	}
	else if(m==n){
		maxv=q[1];
		for(int i=2;i<=n;i++){
			maxv&=q[i];
		}
		cout << maxv;
	}
	else if(f1==1){
		if(m==1){
			cout << q[n];
		}
		else if(m==2){
			cout << int(q[n] & q[n-1]);
		}
		int i=1;
		while(i>=m){
			i*=2;
		}
		i/=2;
		cout << n/i;

		
	} 
	else{
		cout << n/2;
	}
	
	return 0;
}

