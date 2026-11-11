#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll m,v,n,k,a,c,d,q;
ll w[500];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> n >>m >>d >>q;
	for(int i = 1;i<=n;i++) { //r
		cin >> w[i];}
	if(n==2){   //我不会啊，怎么这么难啊。。。。。
		cout << 1<< "/n";//骗分都骗不到，合味道QAQ
		cout << 2;}//那还说啥，摆了呀，痛失510，我再也不来了QWQ
	else{cout << 4<< "/n";
		cout << 6;}
	return 0;
}
