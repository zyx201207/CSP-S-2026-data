#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int b1=0,b2=0,b3=0,b4=0;
	if(c1==c2){
		b1=1;
		int l1,l2;
		l1=s1[0]*10+s1[1];
		l2=s2[0]*10+s2[1];
		if(l1==l2){
			b2=1;
			char p1=s1[2],p2=s2[2];
			bool bl=p1<='C'&&p2<='C';
			bool br=p1>='D'&&p2>='D';
			if(bl||br){
				b3=1;
				if(bl&&abs(p1-p2)==1)
				    b4=1;
				if(br)
				    b4=1;
			}
		}
	}
	cout<<b1<<b2<<b3<<b4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
