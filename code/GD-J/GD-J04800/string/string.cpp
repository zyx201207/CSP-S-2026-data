#include<bits/stdc++.h>
using namespace std;
long long t;
long long c = 0;
long long a[1000008];
string s[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> a[i] >> s[i];
	}
	long long i = 1,j = t;
	for(i;i<j;i){
		if(a[i] >= a[j]){
			if(s[i] != s[j])
			c+= a[j];
			a[i] -= a[j];
			j--;
		}else{
			if(s[i] != s[j])
			c+= a[i];
			a[j] -= a[i];
			i++;
		}
		if(a[i] < 1)i++;
		if(a[j] < 1)j--;
		if(i == j) break;
	}
	cout <<c;
	return 0;
}
