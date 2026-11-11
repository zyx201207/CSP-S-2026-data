//GZ-J00390 铜仁市第五中学 曾凡宇
#include <bits/stdc++.h>
using namespace std;
int main(){
peropen("test","r",stdin);
peropen("test","w",stout;)
char a[5],b[5],c[5],d[5];
int z,f;
cin>>a>>b>>c>>d;
//string.line(c);
if((b[2]-d[2])<2||(d[2]-b[2])<2)
{
	z=1;
}

else z=0;
if(b[2]-d[2]==1||d[2]-b[2]==1)
{
	f=1;
}
else f=0;
if(a[0]==c[0]&&a[1]==c[1])
{
	cout <<"1";
	if(b[0]==d[0]&&b[1]==d[1])
{cout<<"1";
    if(z){
    	cout<<"1";
	}
	else cout << "0";
	if(f){
		cout <<"1";
	}
	else cout << "0";
}
else cout<<"000";
}
else cout << "0000";


return 0;
}
