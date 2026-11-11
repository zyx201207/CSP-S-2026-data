//GZ-J00283 赵宸泽 贵阳市观山湖区第一高级中学 
#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
bool f1,f2,f3;
int main(){
	freopen("r","travel.in",stdin);
	freopen("w","travel.out",stdout);
	cin>>a>>x>>b>>y;
	if(a==b) f1=1;
	if(f1 && (x[0]+x[1]==y[0]+y[1])) f2=1;
	if(f2 && abs(x[2]-y[2])==1 || (x[2]=='C' && y[2]=='D') || (x[2]=='D' && y[2]=='C')) f3=1;
	cout<<f1<<f2<<f3<<f3;
	return 0;
}
