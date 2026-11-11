#include<iostream>
#include<string>
const int N = 1e9+10;
using namespace std;
char s[N];
long long a,n;
char c;
long long sum = 1,ans,num = 0,num1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> a >> c;
		//cout << n << ' ' << a << endl;
		num += a;
		//cout << num  << ' ' << sum<< endl;
		for(long long j = sum;j <= num;j++){
			s[j] = c;
			//cout << c <<' ';
			//cout << j <<' ';
		}
		//cout << endl;
		sum += a;
		//cout << sum << endl;
		//cout << i << endl;
	}
	num1 = num;
	num /= 2;	
	//cout << 1 << endl;
	
	for(long long k = 1;k <= num;k++){
		if(s[k] != s[num1+1-k]){
			ans++;
		}
	}
	//cout << num << ' ' << num1 << ' ' << sum << endl;
	//for(int i = 1;i <= num1;i++)cout << s[i] << ' ';

	cout << ans;
	return 0;
}
