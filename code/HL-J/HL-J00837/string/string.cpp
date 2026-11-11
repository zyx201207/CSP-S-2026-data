#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],i,h=0,j = 0;
char b[200005];
int main(){
	freopen("string6.in","r",stdin);
	freopen("string6.out","w",stdout);
	cin >> n;
	for(i = 0;i <n;i++){
		cin >> a[i] >> b[i];
	}
	while(j <n/2&&i > n/2){	
		if(a[i]!= a[j]){
			if(a[i] > a[j]){
				h += a[j];
				a[i] -= a[j];
				j++;
			}
			else if(a[i] < a[j]){
				h += a[i];
				a[j] -= a[i];
				i++;
			}
			else{
				h += a[i];
				j++;
				i++;
			}
		}
		else{
			if(a[i] > a[j]){
				a[i] -= a[j];
				j++;
			}
			else if(a[i] < a[j]){
				a[j] -= a[i];
				i++;
			}
			else{
				i++;
				j++;
			}
		}
	}
	cout <<h;
	return 0;
}