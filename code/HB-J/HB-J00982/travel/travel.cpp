#include<bits/stdc++.h>


using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int e=0,f=0,g=0,h=0;
	if(a==c){
		e=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			f=1;
			if(int(b[2]<=67)==(int(d[2])<=67)){
				g=1;
				if(int(b[2]>67)){
					h=1;
				}
				else if(max(int(b[2]),int(d[2]))-min(int(b[2]),int(d[2]))==1){
					h=1;
				}
			}
		}
	}
	cout<<e<<f<<g<<h;
	return 0;
}
