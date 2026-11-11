//GZ-J00284 БѕКўжабЇ ЫяЫМем 
#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[1000],x=0,len=0;
	string c; 
	string s;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		len+=a[i];	
	}
	int b=1;
	while(n--){
		for(int j=1;j<=a[b];j++){
			s[a[b-1]+j]=c[b];
		}
		b++;
	}
	if(len%2==0){
		for(int i=1;i<=len/2;i++){
			if(s[i]!=s[len-i+1]) x++;
		}
	}
	else{
		for(int i=1;i<=len/2+1;i++){
			if(s[i]!=s[len-i+1]) x++;
		}
	}
	cout << x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
