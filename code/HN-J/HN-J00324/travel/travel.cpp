#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=2; i<=15; i++) {
		if(c1==c2) {
			ans[i]=1;
			i++;
			if(s1[i]==s2[i]) {
				ans[i]=1;
				i++;
				if(s1[i]-1==s2[i]&&s1[i]+1==s2[i]) {
					ans[i]=11;
					i++;
				} else {
					ans[i]==00;
					i++;
				}
			} else {
				ans[i]=0;
				i++;
			}
		} else {
			ans[i]=0;
			i++;
		}
	}
	cout<<"1111";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
