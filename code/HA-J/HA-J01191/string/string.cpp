#include <bits/stdc++.h>
using namespace std;
string w,c;
long long n,a,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> c;
		for(int i=1;i<=a;i++){
			w+=c;	
		}
	}
	
	long long  t = w.size();
	long long  s = t/2;
	
	long long  j=t-1;
	for(long long i=0;i<=s-1;i++){
		if(w[i]!=w[j]){
			cnt++;
		}
		j--;
	}
	
	
	cout << cnt;
return 0;
}

 

