#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	string s;
	long long sum = 0;
	long long a[n+5];
	char c[n+5];
	for(long long i=1;i<n+5;i++){
		a[i] = 0;
		c[i] = 0;
	}
	
	//输入 
	for(long long i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	
	//复原字符串  对 
	long long sxb = 0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			s[sxb] = c[i];
			sxb ++;
		}
	}
		
	//判断s是否已经是回文串
	bool f = true;
	for(long long i=0;i<sxb/2;i++){
		if(s[i] != s[sxb-i-1]){
			f = false;
		}
	} 
	if(f == true){
		cout << 0;
	}
	
	//不是回文串的 再次判断
	if(f == false){
		for(long long i=0;i<sxb/2;i++){
			if(s[i] != s[sxb-i-1]){
				sum ++;
			}
		} 
		cout << sum;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
