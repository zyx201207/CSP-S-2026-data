//GZ-J00108 黄瀚德
#include <iostream>
using namespace std;
int main{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,n,c;
	int num;
	char c;
	cin >> n;
	for(int j=0,j<n,j++){
		cin >> a >> c;
	}
	for(int p=0,p<n,p++){
		if(a(p-1) !=a(n+1-p)){
			a(p-1) = a(n+1-p);
			num = num +1;
		}
	}
	cout << num;
	return 0;
}
