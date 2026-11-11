//GZ-J00198 遵义市第一初级中学 黄君豪
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[6]={0};
	char b[6]={0};
	char c[6]={0};
	char d[6]={0};
	cin>>a>>b;
	cin>>c>>d;
	string s;
	bool o=0;
	if(a[0]==c[0] and a[1]==c[1]) s+="1";
	if(a[0]!=c[0] or a[1]!=c[1]) s+="0";
	if(b[0]==d[0] and b[1]==d[1]) s+="1";
	if(b[0]!=d[0] or b[1]!=d[1]) s+="0";
	if(((b[2]=='D' or b[2]=='E') and (d[2]=='D' or d[2]=='E')) or((b[2]!='D' and b[2]!='E') and (d[2]!='D' and d[2]!='E'))){
		s+="1";
		o=1;
	}
	else{
		s+="0";
	}
	if((o and b[2]+1==d[2]) or (o and b[2]==d[2]+1)) s+="1";
	else s+="0";
	cout<<s;
	fclose(stdin);
	fclose(stdout);
}

