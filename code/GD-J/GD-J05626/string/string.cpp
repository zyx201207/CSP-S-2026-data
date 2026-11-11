#include<iostream>
#include<string>
using namespace std;

int a[200010];
char b[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,mid = 0,sum = 0;
	cin >> n;
	n++;
	mid = n/2;
	n--;
	int j = n-1;
	string s;
	for(int i = 0+-; i <= n; i++){
		cin >> a[i];
		cin >> b[i];
		for(int j = 0; j <=a[i]; j++){
			s += b[i];
		}
		
	}
	for(int i = 0; i < mid;i++){
		if(s[i] != s[int(s.size())+1 - i]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
