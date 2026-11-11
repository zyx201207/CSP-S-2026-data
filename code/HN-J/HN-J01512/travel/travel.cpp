#include <bits/stdc++.h>
using namespace std;
bool flag,flag1,flag2,flag3;
int main()
{	
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string s1;
	string s2;
	string c1;
	string c2;
	int cnt = 0;
	cin>>c1>>s1>>c2>>s2;
	for(int i = 0;i<2;i++){
		if (c1[i] == c2[i]){
			cnt++;
		}
	}
	if (cnt == 2){
		flag = 1;
	}
	cnt = 0;
	if (flag){
		for(int i = 0;i<2;i++){
			if (s1[i] == s2[i]){
				cnt++;
			}
		}
		if (cnt == 2){
			flag1 = 1;
		}
		if (flag1){
			if ((s1[2] <= 'C' && s2[2] <= 'C')||(s1[2] >= 'D' && s2[2] >= 'D')){
				flag2 = 1;
			}
			if (flag2){
				if (s1[2]+1 == s2[2] || s1[2]-1 == s2[2]){
					flag3 = 1;
				}
			}
		}
	}
	cout<<flag<<flag1<<flag2<<flag3;
	return 0;
}
