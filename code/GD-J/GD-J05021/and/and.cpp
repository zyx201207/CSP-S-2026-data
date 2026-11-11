#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k;
int a[2010],b[2010];
int cmp(int a,int b){
	return a>b;
}
int cmp1(int a,int b){
	return a&k>b&k;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	cin >> a[0];
	b[0]=a[0];
	for(int i = 1;i < n;i++){
		cin >> a[i];
		b[i]=(b[i-1]&a[i]);
	}
	if(n<=20){
		int max_n=-1;
		for(int i = 0;i < n;i++){
			sort(a,a+n,cmp);
			int k = a[i];
			int cnt = 1;
			while(m){
				sort(a+cnt,a+n,cmp1);
				for(int i = 0;i < n;i++)cout << a[i] << ' ';
				cout << endl;
				k&=a[cnt];
				cnt++;
				m--;
			}
			if(max_n<k)max_n=k;
		}
		cout << max_n;
	}
	else{
		sort(a,a+n,cmp);
		if(n==m)cout << b[n-1];
		else if(m==1){
			cout << a[0];
		}
		else if(m==2){
			int max_n=-1;
			if(n>10000){
				for(int i = 0;i < n/4;i++){
					for(int j = i+1;j <= n/4;j++){
						if(max_n<(a[i]&a[j]))max_n=(a[i]&a[j]);
					}
				}
			}
			else{
				for(int i = 0;i < n-1;i++){
					for(int j = i+1;j < n;j++){
						if(max_n<(a[i]&a[j]))max_n=(a[i]&a[j]);
					}
				}
			}
			cout << max_n;
		}
	}
	return 0;
}
