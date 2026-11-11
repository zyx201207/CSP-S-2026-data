//GZ-J00643 个人报名 周晨诚
#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],z=0,m = 0;
string c[200005];
vector<string> s,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		if(i > 0){
			if(a[i] == a[i-1]){
				m++;
			}
		}
	}
	if(m == n - 1){
		for(int i=0;i<n;i++){
			s.push_back(c[i]);
		}
	} else {
		for(int i=0;i<n;i++){
			for(int j =0;j<a[i];j++){
				s.push_back(c[i]);
			}
 		}
	}
	for(int i=s.size()-1;i>=0;i--) {
		x.push_back(s[i]);
	}
	for(int i=0;i<s.size();i++){
		if(x[i] != s[i]){
			z++;
		}
	}
	if(m == n - 1){
		z *= a[0];
	}
	z /= 2;
	cout << z << endl;
	return 0;
} 
