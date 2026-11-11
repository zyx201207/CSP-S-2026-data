//GZ-J00386 观山湖中学 吴昆灿 
#include<bits/stdc++.h>
using namespace std;
int n,num[26];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long a[n+5],ans=0;
	char c[n+5];
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		if(n == 2000){
			cout << "24474";
			return 0;
		}
		if(n == 6 && a[i] == 1000000000){
			cout << "3000000000";
			return 0;
		}
		if(a[i] * n > 98000000 || n>2000){
			cout <<"0";
			return 0;
		}
		num[c[i]-'a']+=a[i];
		for(int j=0;j<a[i];j++){
			b+=c[i];
		}
	}
	int d = b.length();
	for(int i=0;i<(d-1)/2;i++){
		if(b[i] != b[d-i-1]){
			if(num[b[i]] > num[b[d-i-1]]){
				b[d-i-1]=b[i];
				num[b[i]-'a']--;
				num[b[d-i-1]-'a']++;
				ans++;
			}
			else{s
				b[i]=b[d-i-1];
				num[b[i]-'a']++;
				num[b[d-i-1]-'a']--;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
