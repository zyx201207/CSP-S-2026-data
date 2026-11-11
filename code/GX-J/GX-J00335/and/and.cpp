#include<bits/stdc++.h>
using namespace std;


long long n,m,a[1000010],x = 0;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;

    for(int i = 0;i <n;i++){
		 cin >> a[i];
	}
	if(m != 1){
		for(int i = 0;i <n;i++){
			for(int j = i+1;j < n;j++){
				if((a[i] & a[j]) > x){
				x = (a[i] & a[j]);
				}
			}
		}
	}
	else if(m == 1){
		for(int i = 0;i < n;i++){
			x = a[i];
		}
	}
	cout << x;
    return 0;
}
