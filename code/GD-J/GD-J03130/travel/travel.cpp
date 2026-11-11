#include<bits/stdc++.h>
using namespace std;
#define fname "travel"
string ax,ay,an,am,bx,by,bn,bm;
int main(){
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	cin>>ax>>ay>>bx>>by;
	for(int i=0;i<=2;i++){
		if(i<=1){
			an+=ay[i];
			bn+=by[i];
		}else{
			am+=ay[i];
			bm+=by[i];
		}
	}
	
	if(ax!=bx){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		if(an!=bn){
			cout<<"000";
			return 0;
		}else{
			cout<<1;
			if(am<="C"&&bm<="C"||am>="D"&&bm>="D"){
				cout<<"1";
				if(am>="D"&&bm>="D"){
					cout<<"1";
				}else if(am=="B"||bm=="B"){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
				return 0;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
	
} 
