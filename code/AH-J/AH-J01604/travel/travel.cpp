#include<bits/stdc++.h>
using namespace std;
string cn;
bool f1,f2,f3,f4;
int l,r;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	getline(cin,cn);
	if(cn[0]==cn[7]&&cn[1]==cn[8]){
		f1=1;
		if(cn[3]==cn[10]&&cn[4]==cn[11]){
			f2=1;
			if(cn[5]=='A'||cn[5]=='B'||cn[5]=='C')l++;
			if(cn[5]=='D'||cn[5]=='F')r++;
			if(cn[12]=='A'||cn[12]=='B'||cn[12]=='C')l++;
			if(cn[12]=='D'||cn[12]=='F')r++;
			if(l!=r){
				f3=1;
				if((cn[5]=='A'&&cn[12]=='B')||(cn[5]=='B'&&(cn[12]=='A'||cn[12]=='C'))||(cn[5]=='C'&&cn[12]=='B')||(cn[5]=='D'&&cn[12]=='F')||(cn[5]=='F'&&cn[12]=='D')){
					f4=1;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	
	return 0;
}
