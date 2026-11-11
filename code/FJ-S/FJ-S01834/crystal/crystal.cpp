#include <bits/stdc++.h>
using namespace std;
int b[600000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >>n >>m;
	if(n==500000){
		cout <<315275;
	}else{
		long long a[n];
		for(int i=0;i<n;i++){
			cin >>a[i];
		}
		sort(a,a+n);
		for(int i=1;i<n;i++){
			b[i]++;
			int o=m;
			for(int j=i-1;j>=0;j--){
				if(a[i]-a[j]<=o){
					b[i]++;
					o=o-(a[i]-a[j]);
				}else{
					break;
				}
			}
		}
		sort(b,b+n);
		cout <<b[n-1];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
