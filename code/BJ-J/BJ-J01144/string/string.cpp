#include <bits/stdc++.h>
using namespace std;

long long a[10000010];
char s[1000010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for (long long i=0;i<n;i++){
		cin >> a[i] >> s[i];
		//cout << "/" << i << "/" << endl;
	}
	long long l=0,r=n-1;
	long long m=0;
	long long sum=0;
	while (l<r){
		m=a[l]-a[r];
		//cout << a[l] << " " << a[r] << " " << m << endl;
		if (m==0){
			if (s[l]!=s[r]){
				sum+=a[l];
			}
			l++;
			r--;
		}else if (m>0){
			if (s[l]!=s[r]){
				sum+=a[r];
			}
			r--;
			a[l]=m;
		}else{
			if (s[l]!=s[r]){
				sum+=a[l];
			}
			l++;
			//cout << a[r] << endl;
			a[r]=-m;
		}
		//cout << m << " " << l << " " << r << endl;
		//if (p){
			//a[r]+=m;
		//}
		//cout << l << " " << r << endl;
	}
	cout << sum;
	//cout << endl;
	//for (int i=0;i<n;i++){
		//cout << a[i] << " ";
	//}
}
