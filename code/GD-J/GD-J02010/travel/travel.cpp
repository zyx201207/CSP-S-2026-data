#include<bits/stdc++.h>
#define longlong long long
//#define longlong __int128_t
#define ll (longlong)
namespace NOTLE{
	void NOTLE(){
		std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
	void NO_TLE(){
//		std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
}
using namespace std;
bool frein=false,freout=false,refrein=false;
int a,b,n,m,x,y;
signed main(){
	NOTLE::NOTLE();//samples:5
	freopen("travel.in","r",stdin),frein=true;
	freopen("travel.out","w",stdout),freout=true;
	refrein=(frein and not(freout));
	{
		string str;
		cin>>str;
		if(refrein)	cout<<str<<' ';
		for(int i=0;i<(int)str.length();i++){
			a=(a*10)+(str[i]-'0');
		}
	}
	{
		string str;
		cin>>str;
		if(refrein)	cout<<str<<' ';
		for(int i=0;i<(int)str.length();i++){
			if('0'<=str[i] and str[i]<='9')	n=(n*10)+(str[i]-'0');
			else	x=str[i]-'A'+1;
		}
	}
	{
		string str;
		cin>>str;
		if(refrein)	cout<<str<<' ';
		for(int i=0;i<(int)str.length();i++){
			b=(b*10)+(str[i]-'0');
		}
	}
	{
		string str;
		cin>>str;
		if(refrein)	cout<<str<<' ';
		for(int i=0;i<(int)str.length();i++){
			if('0'<=str[i] and str[i]<='9')	m=(m*10)+(str[i]-'0');
			else	y=str[i]-'A'+1;
		}
	}
	if(x==6)	x--;
	if(y==6)	y--;
	if(refrein)	cout<<'\n';
	if(a==b){
		cout<<'1';
		if(n==m){
			cout<<'1';
			if((x<=3 and y<=3) or (4<=x and 4<=y)){
				cout<<'1';
				if((x-y==-1) or (x-y==1))	cout<<'1';
				else	cout<<'0';
			}
			else	cout<<'0'<<'0';
		}
		else	cout<<'0'<<'0'<<'0';
	}
	else	cout<<'0'<<'0'<<'0'<<'0';
	cout<<'\n';
	return 0;
}
