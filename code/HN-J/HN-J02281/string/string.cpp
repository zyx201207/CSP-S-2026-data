#include <bits/stdc++.h>
using namespace std;
long long n,a,sum;
string s,c; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a >> c;
		for (int j=0;j<a;j++){
			s+=c;
		}
	}
	long long len=s.size();
	if (len%2==1){
		for (int i=0;i<len/2+1;i++){
			if (i==(len-i-1)){
				break;
			}
			else if(s[i]!=s[len-i-1]){
				sum++;
			}
		}
	}
	else{
		for (int i=0;i<len/2;i++){
		if (s[i]!=s[len-i-1]){
			sum++;
		}
	}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
