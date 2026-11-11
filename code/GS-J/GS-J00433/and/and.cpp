#include<bits/stdc++.h>
using namespace std;

long long a[20010];
long long maxn = -1;
//Ê®×ª¶þ// 
string vto(long long x){  
	string r;
	while(x >= 2){
		if(x % 2 == 0) r += "0";
		else r += "1";
		x /= 2;
	}
	if(x % 2 == 0) r += "0";
	else r += "1";
	return r;
}
//-----//

long long otv(string x){
	long long ans = 0;
	for(int i = 0;i < x.size();i++){
		int k = x[i] - '0';
		ans += pow(2,i)*k;
	}
	return ans;
}

long long tr(long long a,long long b){
	string r;
	string k1 = vto(a);
	string k2 = vto(b);
	for(int i = 0;i < min(k1.size(),k2.size());i++){
		if(k1[i]==k2[i]) r += k1[i];
		else r += "0"; 
	}
	
	return otv(r);
}


int n,m;

int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		for(int i = 1;i <= n;i++){
			maxn = max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
	if(m == n){
		long long val = a[1];
		for(int i = 2;i <= n;i++){
			val = tr(val,a[i]);	
		}	
		maxn = max(val,maxn);
		cout << maxn;
		return 0;
	}
	
	for(int i = 1;i <= n;i++){	
		if(n - i + 1 < m) break;
		
		for(int start = i+1;start <= n-m+1;start++){
			long long val = a[i];
			for(int j = 1;j < m;j++){
				val = tr(val,a[j+start]);
			}
			maxn = max(maxn,val);	
		}
	}
	cout << maxn;
	
	return 0;
}

