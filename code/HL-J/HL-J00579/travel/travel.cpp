#include <bits/stdc++.h>
using namespace std;
char c_1[10],s_1[10],c_2[10],s_2[10]; int fir,sec;
int main ()
    {
    
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int i=1;i<=2;i++){char z;cin>>z;c_1[i]=z;}
	for (int i=1;i<=3;i++){char z;cin>>z;s_1[i]=z;}
	for (int i=1;i<=2;i++){char z;cin>>z;c_2[i]=z;}
	for (int i=1;i<=3;i++){char z;cin>>z;s_2[i]=z;}
	
	//cout<<c_1[1]<<c_1[2]<<" ";cout<<s_1[1]<<s_1[2]<<s_1[3]<<" "<<endl;
	//cout<<c_2[1]<<c_2[2]<<" ";cout<<s_2[1]<<s_2[2]<<s_2[3]<<" "<<endl;
	
	if(c_1[1]==c_2[1] && c_1[2]==c_2[2]) fir=1;
	else {cout<<"0000"; return 0;}
	if(s_1[1]==s_2[1] && s_1[2]==s_2[2]) sec=1;
	else {cout<<"1000"; return 0;}
	
	int a=int(s_1[3]), b=int(s_2[3]);
	if(a<=67 && b<=67) 
		{
		if (a+1==b || b+1==a) 
			{
			cout<<"1111";
			return 0;
			}
		else 
			{
			cout<<"1110";
			return 0;
			}
		}
	else 
		{
		if (a>=68 && b>=68)
			{
			cout<<"1111";
			return 0;
			}
		else 
			{
			cout<<"1100";
			}
		}
    return 0;
    }
