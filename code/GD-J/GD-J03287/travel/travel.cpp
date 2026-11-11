#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;//º¥c1,c2,s1,s2| 
	char x,y;
	int r[4];
	bool lr[2]={0,0};
	cin>>a>>c>>x>>b>>d>>y;
	if(a==b){  //≥µœ·≈–∂œ 
		r[0]=1;
	}else{
		r[0]=0;
	}
	if(r[0]&&c==d){  //Õ¨≈≈≈–∂œ 
		r[1]=1;
	}else{
		r[1]=0;
	}
	if(x-'A'<3){  //◊Û”“≤‡≈–∂œ 
		lr[0]=1;
	}else{
		lr[1]=1;
	}
	if(y-'A'<3){
		lr[0]=1;
	}else{
		lr[1]=1;
	}
	if(r[1]&&(lr[0]!=lr[1])){
		r[2]=1;
	}else{
		r[2]=0;
	}
	if(r[2]&&(max(x-y,y-x)==1)){
		r[3]=1;
	}else{
		r[3]=0;
	}
	cout<<r[0]<<r[1]<<r[2]<<r[3];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
