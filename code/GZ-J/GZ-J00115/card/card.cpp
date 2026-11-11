//准考证号：GZ-J00115学校：六盘水市第二十四中学姓名：周启明
#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500005],v[300005];
bool f[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}for (int i = n;i >= 1;i--){
		if (!f[a[i]]){
			f[a[i]] = 1;
			v[a[i]] = i;
		}
	}for (int i = 1;i <= m;i++){
		cout << v[i] << " ";
	}
	return 0;
}
