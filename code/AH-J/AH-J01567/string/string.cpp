#include <iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long a[n]; char c[n]; long long cnt=0;
	string s="";
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	int m=s.size();
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-i-1]){
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}
