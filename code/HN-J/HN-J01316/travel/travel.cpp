#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,s1,c2,s2,f1=0,f2=0,f3=0,f4=0;
	char s11,s22;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>s11>>c2>>s2>>s22;
	if( c1 == c2 ){
		f1=1;
		if( s1 == s2 && s11 != s22 ){
			f2=1;
			if( s11 == 'F' && s22 == 'D' || s11 == 'D' && s22 == 'F' ){
				f3=1;
				f4=1;
			}else if( s11 == 'C' && s22 == 'D' || s11 == 'D' && s22 == 'C' ){
				f3=0;
				f4=0;
			}else{
				f3=1;
				if( s11-s22 == 1 || s11-s22 == -1 ){
					f4=1;
				}
			}
		}
		
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
