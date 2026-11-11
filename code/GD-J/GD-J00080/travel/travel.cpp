#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
//	cout<<a1<<' '<<a2<<' '<<b1<<' '<<b2<<endl;
	if(a1!=b1)
	{
			cout<<"0000"<<endl;
			return 0;
	}
	cout<<1;
	if(!((a2[0]==b2[0])&&(a2[1]==b2[1]))){
		cout<<"000"<<endl;
		return 0;
	}	
	cout<<1;
	int x=a2[2]-'A',y=b2[2]-'A';
	if(y<x)
		swap(x,y);
	if(!((x<=2&&y<=2)||(x>=3&&y>=3)))
	{
		cout<<"00"<<endl;
		return 0;
	}
	cout<<1;
	if((y-x==1&&y!=3)||(x==3&&y==5))
		cout<<1;
	else
		cout<<0;
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
