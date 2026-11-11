#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[10][25];
struct stu{
	int cxh;//车厢号 
	int pai;//排 
	int zwo;//座 ABCDF 
}r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		r.cxh=r.cxh*10+c1[i]-'0';
		x.cxh=x.cxh*10+c2[i]-'0';
		r.pai=r.pai*10+s1[i]-'0';
		x.pai=x.pai*10+s2[i]-'0';
	} 
	switch(s1[2]){
		case 'A':r.zwo=1;break;
		case 'B':r.zwo=2;break;
		case 'C':r.zwo=3;break;
		case 'D':r.zwo=5;break;
		case 'F':r.zwo=6;break;
	}
	switch(s2[2]){
		case 'A':x.zwo=1;break;
		case 'B':x.zwo=2;break;
		case 'C':x.zwo=3;break;
		case 'D':x.zwo=5;break;
		case 'F':x.zwo=6;break;
	}
	if(r.cxh!=x.cxh){//是否在同一节车厢
		cout<<"0000";
		return 0;
	}else{
		if(r.cxh==x.cxh){
			cout<<"1";
			a[r.zwo][r.pai]=1;
			a[x.zwo][x.pai]=1;
		}
		if(r.pai==x.pai){//是否在同一节车厢的同一排
			cout<<"1";
			if( (r.zwo>=1 && r.zwo<=3 && x.zwo>=1 && x.zwo<=3) || (r.zwo>=5 && r.zwo<=6 && x.zwo>=5 && x.zwo<=6) ){
				cout<<"1";
				if(a[r.zwo+1][r.pai]==1 || a[r.zwo-1][r.pai]==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	return 0;
} 
