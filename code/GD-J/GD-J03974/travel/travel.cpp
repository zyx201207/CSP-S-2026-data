#include<bits/stdc++.h>
using namespace std;
bool a=0,b=0,c=0,d=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,a1,a2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
		a1=s1[0]+s1[1];
		a2=s2[0]+s2[1];
		if(a&&a1==a2){
			b=1;
			a1=s1[2];
			a2=s2[2];
			if(b==1 && ((a1=="D" || a1=="F") && (a2=="D" || a2=="F")) || ((a1=="A" || a1=="B" || a1=="C") && (a2=="A" || a2=="B" || a2=="C"))){
				c=1;
				if(c==1 && ((a1=="D" && a2=="F" || a2=="D" && a1=="F") || (a1=="A" && a2=="B" || a1=="B" && a2=="A" || a1=="B" && a2=="C" || a1=="C" && a2=="B"))){
					d=1;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
