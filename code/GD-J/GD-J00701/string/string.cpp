#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char a[N];
long long x[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> x[i] >> a[i];
	}
	long long sum=0;
	int i=1,j=n;
	while(i<j){
		if(a[i]==a[j]){
			if(x[i]==x[j]){
				i++;
				j--;
				continue;
			}else if(x[i]>x[j]){
				x[i] -=x[j];
				j--;
			}else{
				x[j] -=x[i];
				i++;
			}
		}else{
			if(x[i]==x[j]){
				sum +=x[i];
				i++;
				j--;
			}else if(x[i]>x[j]){
				sum +=x[j];
				x[i] -=x[j];
				j--;
			}else{
				sum +=x[i];
				x[j] -=x[i];
				i++;
			}
		}
	}
	cout << sum;
	return 0;
}
