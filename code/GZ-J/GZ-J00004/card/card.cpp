//准考证号：GZ-J00004 姓名：龚兴漩 
#include <bits/stdc++.h>

int cd[500005];
int ey[300005];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++) {
		scanf("%d",&cd[i]);
	}
	for(int i = 0;i<n;i++) {
		std::string str;
		for(int j = i;j<n;j++) {
			int ix;
			bool rp = false;
			if(str.find(cd[j]+'0') != std::string::npos) {
				ix = str.find(cd[j]+'0');
				rp = true;
			}
			if(rp) {
				int eraselength = str.length() - ix - 1;
				str.erase(ix);
			}
			str+=cd[j]+'0';
		}
		for(int j = 0;j<str.length();j++) {
			ey[str[j]-'0']++;
		}
	}
	for(int i = 1;i<=m;i++)
		printf("%d ",ey[i]);
	return 0;
}
