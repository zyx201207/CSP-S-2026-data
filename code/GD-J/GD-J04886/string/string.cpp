#include <iostream>
#include <cstring>
using namespace std;
struct noi{
	int a;
	char c;
}a[676767];
char s[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum = 0,cnt = 0,j = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i].a >> a[i].c;
		cnt += a[i].a;
		for(j;j < cnt;j++){
			s[j] = a[i].c;
		}
	}for(int i = 0;i < cnt / 2;i++){
		int k = cnt - i - 1;
		if(s[i] != s[k]){
			sum++;
		}
	}cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
