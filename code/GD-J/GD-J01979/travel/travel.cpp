#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d,p1,p2;
char zuowei1,zuowei2;//zuowei=座位编号 
bool chk(char a,char b){
	//两种情况
	//分别在国道的两侧(df,abc)两种 
	if((a=='D'&&b=='F')||(a=='F'&&b=='D'))return 1;
	if((a=='C'&&b=='B')||(a=='C'&&b=='A')||(a=='B'&&b=='A'))return 1;
	if((a=='B'&&b=='C')||(a=='A'&&b=='C')||(a=='A'&&b=='B'))return 1;
	return  0;
}
bool chk2(char a,char b){
	//cout<<abs(a-b)<<'\n';
	//编号是否相邻， 
	//update1:注意过道！！！！！！！ 
	if(abs(a-b)==1&&(a!='C'&&b!='D')&&(a!='D'&&b!='C'))
	return 1;
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	cout<<(a==c);
	for(int i=0;i<2;i++){
		p1+=b[i];
		p2+=d[i];
	}
	cout<<((p1==p2)&&(a==c));
	zuowei1=b[2],zuowei2=d[2];
	//cout<<'\n'<<zuowei1<<' '<<zuowei2<<'\n';
	cout<<(p1==p2&&chk(zuowei1,zuowei2)&&(a==c));
	if((p1==p2&&chk(zuowei1,zuowei2))&&chk2(zuowei1,zuowei2)&&(a==c))cout<<1;
	else cout<<0;;
	return 0;
}
