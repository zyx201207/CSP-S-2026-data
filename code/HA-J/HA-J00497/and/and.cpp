//and
#include <bits/stdc++.h>
using namespace std;

int n,m; 

struct stu{
	int num,sum;
}a[200005];

bool cmp(stu x,stu y){
	if (x.sum == y.sum){
		return x.num > y.num;
	}
	return x.sum > y.sum;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i ++){
		cin>>a[i].num;
		int tmp = a[i].num;
		while (tmp > 0){
			a[i].sum += tmp % 2;
			tmp /= 2;
		}
	}
	sort(a + 1,a + n + 1,cmp);
	cout<<a[m].num;
	return 0;
}
