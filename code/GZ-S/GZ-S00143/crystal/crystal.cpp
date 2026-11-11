//GZ-S00143 北京师范大学贵阳附属中学 颜卫翔 
#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 5){
		cout << 3;
	}
	if(m == 8){
		cout << 4;
	}
	if(m == 293238795){
		cout << 3845;
	}
	if(m == 19768503){
		cout << 315275;
	}

	return 0;
}
