#include <bits/stdc++.h>
using namespace std;
struct nb{
	int num=0;
	char ch;
	void pushin(){
		cin >> num >> ch;
	}
};
nb hw[300005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		hw[i].pushin();
		if(hw[i].ch!='a'){
			cnt+=hw[i].num;
		}
	}cout << cnt;
	return 0;
}
