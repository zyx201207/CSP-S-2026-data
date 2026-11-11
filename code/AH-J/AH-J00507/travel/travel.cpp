#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a1,a2,s1,s2;
bool k[5],y;
char c[5] = {'A','B','C','D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> s1 >> a2 >> s2;
	if(a1 == a2)k[0]=1;
	if(k[0]&&(s1[0] == s2[0])&&(s1[1] == s2[1]))k[1]=1;
	if((s1[2] == c[0]&&s2[2] == c[1])||(s1[2] == c[0]&&s2[2] == c[2])||(s1[2] == c[1]&&s2[2] == c[0])||(s1[2] == c[1]&&s2[2] == c[2])||(s1[2] == c[2]&&s2[2] == c[1])||(s1[2] == c[2]&&s2[2] == c[0])||(s1[2] == c[4]&&s2[2] == c[5])||(a1[2] == c[5]&&a2[2] == c[4]))y = 1;
	if(k[1]&&y)k[2]=1;
	y = 0;
	if((s1[2] == c[0]&&s2[2] == c[1])||(s1[2] == c[1]&&s2[2] == c[0])||(s1[2] == c[1]&&s2[2] == c[2])||(s1[2] == c[2]&&s2[2] == c[1])||(s1[2] == c[4]&&s2[2] == c[5])||(s1[2] == c[5]&&s2[2] == c[4]))y = 1;
	if(k[2]&&y)k[3] = 1;
	cout <<k[0]<<k[1]<<k[2]<<k[3];
	return 0;
}
