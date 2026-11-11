//准考证号：GZ-J00004 姓名：龚兴漩 
#include <bits/stdc++.h>

int num[200005];

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++)
		scanf("%d",&num[i]);
	if(m == 1) {
		int mx = 0;
		for(int i = 0;i<n;i++)
			mx = std::max(num[i],mx);
		printf("%d",mx);
		return 0;
	}
	if(m == 2) {
		int mx = 0;
		for(int i = 0;i<n;i++) {
			for(int j = n-1;j>i;j--) {
				int x = num[i] & num[j];
				mx = std::max(mx,x);
			}
		}
		printf("%d",mx);
		return 0;
	}
	return 0;
}
