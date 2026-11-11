#include<bits/stdc++.h>
using namespace std;
int n;
long long x;
string m;
char y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long t=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> x;
		cin >> y;
		for(int j=0;j<x;j++){
			m[t]=y;
			t++;
		}
	}

	long long sum=0;
	t-=1;
	for(long long i=0;i<=t;i++){
		if(m[i]!=m[t]){
			sum++;
			t--;
		}else{
			t--;
			continue;
		}

	}
	cout << sum;
	return 0;
} 
