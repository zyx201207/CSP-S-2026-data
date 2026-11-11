
#include <bits/stdc++.h>
using namespace std;
char c1[21],c2[21],s1[21],s2[21],ans[10];
bool a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
	int l1 = strlen(c1+1),l2 = strlen(c2+1);
	bool f = 1;
	for (int i = 1;i <= l1;i++){
		if (c1[i] != c2[i]){
			f = 0;
		}
	}
	if (f)
		ans[1] = 1;
	if (ans[1] == 1 && s1[1] == s2[1] && s1[2] == s2[2])
		ans[2] = 1;
	if (s1[3] == 'D' || s1[3] == 'F')
		a = 1;
	else
		a = 0;
	if (s2[3] == 'D' || s2[3] == 'F')
		b = 1;
	else
		b = 0;
	if (ans[2] == 1 && a == b)
		ans[3] = 1;
	if (ans[3] == 1 && s1[3] + 1 == s2[3])
		ans[4] = 1;
	for (int i = 1;i <= 4;i++)
		printf("%d ",ans[i]);
	return 0;
}
