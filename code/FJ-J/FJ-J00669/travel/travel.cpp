#include<bits/stdc++.h>
using namespace std;
string c1,z1,c2,z2;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>z1>>c2>>z2;
	if(c1==c2){
		a[1]=1;
		string j1=z1.substr(0,2),j2=z2.substr(0,2);
		if(j1==j2){   //在同一排 
			a[2]=1;
			j1=z1[2],j2=z2[2];
			if( (j1>="D"&&j2>="D")||(j1<="C"&&j2<="C") ){  //在同一过道 
				a[3]=1;
				int s=j1[0]-j2[0]; 
				if(abs(s)==1) a[4]=1;
			} 
		}
	}
	for(int i=1;i<=4;i++) cout<<a[i];
}
