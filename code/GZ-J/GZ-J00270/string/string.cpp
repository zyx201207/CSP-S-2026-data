//GZ-J00270,贵阳市第一实验中学，闵梦琪
#include<bits/stdc++.h>
using namespace std;
int a[1000005],m,q;
int main(){
	int n,cnt=0;
	char c[105];
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		if(c[i]!=c[i-1] && i!=1){
			q = a[i],m=i;
		}
	}
	if(q == 0|| c[1]==c[m]&&a[1]==q){
		cout << 0;
	}else if(c[1]==c[m] && a[1]!=q){
		int ma = max(q,a[1]);
		int mi = min(q,a[1]);
		cout << ma-mi;
	}else{
		cout << a[1];
	}
	return 0;
}
