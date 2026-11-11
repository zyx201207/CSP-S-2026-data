#include <bits/stdc++.h>
using namespace std;
char a[5],b[5],c[5],d[5];
int ans1=0,ans2=0,ans3=0,ans4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1]>>a[2]>>b[1]>>b[2]>>b[3]>>c[1]>>c[2]>>d[1]>>d[2]>>d[3];
	if(a[1]==c[1]&&a[2]==c[2])
	ans1=1;
	if(ans1==1&&b[1]==d[1]&&b[2]==d[2])
	ans2=1;
	char cc=b[3],ccc=d[3];
	if(ans2==1&&abs(cc-ccc)==1)
	ans3=1;
	if((b[3]=='C'&&d[3]=='D')||(b[3]=='D'&&d[3]=='C'))
	ans3=0;
	if(ans1==1&&ans2==1&&ans3==1)
	ans4=1;
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
