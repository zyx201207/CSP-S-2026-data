//GZ-J00327 遵义市第十九中学 张锣址杨 
#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n>> m;
	long long a[n+5],b[n+5],num=0;
	for(long long i= 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(long long i = n-1;i >n-m;i--){
		if(i==0){
			num=a[i];
			break;
		}
		a[i-1]=a[i]&a[i-1];
		num=a[i-1];
}
	cout <<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

