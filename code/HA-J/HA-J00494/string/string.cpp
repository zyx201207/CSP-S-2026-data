#include <iostream>
#include <string>
using namespace std;

long long n,a[101201];
string sum;
char c[101201];

int hwans(string h){
	int l=1,r=h.length(),num=0;
	while(l!=r){
		if (h[l]==h[r]){
			l++;
			r--;
		}
		else if (h[l]!=h[r]){
			num++;
		}
	}
	return num;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for (int j=1;j<=a[i];j++){
			sum+=c[i];
		}
	}
	cout<<hwans(sum);
	return 0;
}
