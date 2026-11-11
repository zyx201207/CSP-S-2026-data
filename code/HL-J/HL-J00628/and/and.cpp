#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n;
	int a[2001];
	for(int i = 1; i <= n;i++)
		cin>> a[i];
	int t = 0;
	for(int i = 1; i <= n;i++){
		for(int j = i + 1; j <= n - i; j++){
			if((a[i] and a[j]) > t){
				t = a[i] and a[j];
			}
		}
	}
	cout<<t;
	return 0;
}
