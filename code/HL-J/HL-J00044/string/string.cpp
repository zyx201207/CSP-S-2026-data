#include <bits/stdc++.h>
using namespace std;
int n,a[10001],c[10001],m=0,num=0,z=0;
char b[10001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
		num+=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=a[i];j++){
			c[m]=b[i];
			m++;
		}
	}
	if (num%2==0){
		for (int i=1;i<=num/2;i++){
			if(!(c[i]==c[num-i+1])){
				z++;
			}
		}
	}else{
		for(int i=1;i<=(num-1)/2;i++){
			if(!(c[i]==c[num-i+1])){
				z++;
			}
		}
	}
	cout << z;
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
