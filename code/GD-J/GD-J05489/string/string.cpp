#include<iostream>
using namespace std;
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	long long sum = 0;
	for(int i = 0;i < n;i++){
		char ch;
		cin >> a[i] >> ch;
		sum += a[i];
		long long k = sum - a[i];
		for(int j = k;j < sum;j++){
			s[j] = ch;
		}
	}
	long long ans = 0,i = 0,j = sum - 1;
	while(i <= j){
		if(s[i] != s[j])ans++;
		i++,j--;
	}
	cout << ans << endl;
	return 0;
}
