#include<bits/stdc++.h>
using namespace std;
short mp[200];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['F']=2;
	int c1,s11,c2,s21;
	char s12,s22;
	scanf("%d %d%c %d %d%c",&c1,&s11,&s12,&c2,&s21,&s22);
	bool flag=(c1==c2);
	cout<<flag;
//	cerr<<'\n'<<s11<<' '<<s12<<'\n';
	flag&=(s11==s21);
	cout<<flag;
	flag&=(mp[(int)s12]==mp[(int)s22]);
	cout<<flag;
	flag&=(s12=='D'&&s22=='F'||s12=='F'&&s22=='D'||s12+1==s22||s22+1==s12);
	cout<<flag;
	return 0;
}
