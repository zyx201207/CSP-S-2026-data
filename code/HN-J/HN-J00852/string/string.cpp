#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+50;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	long long sum=0;
	long long i=1,j=n;
	while(i<j){
		if(c[i]!=c[j]) sum+=min(a[i],a[j]);
		if(a[i]==a[j]){
			i++;
			j--;
		}else if(a[i]>a[j]){
			a[i]-=a[j];
			j--;
		}else{
			a[j]-=a[i];
			i++;
		}
	}
	cout << sum << endl;
}
