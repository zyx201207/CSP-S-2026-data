#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long c=0;
	long long q[n];
	string w;
	
	long long cnt=0;
	
	string a;

	for(int i=0;i<n;i++){
		cin >> q[i];
		cin >> w[i];
		for(int j=cnt;j<q[i]+cnt;j++){
			a[j]=w[i];
		}
		cnt+=q[i];
	}



for(int i=0;i<cnt/2;i++){
	if(a[i]!=a[i+cnt/2]){c++;}
}
cout << c;
	
	return 0;
}
