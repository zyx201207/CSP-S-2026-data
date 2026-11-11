#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;//1指 R的信息 ，c指车厢 
bool a[10+5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a[1]=1;
	else a[1]=0;
	//两张车票对应的座位是否在同一节车厢；
	int sr=s1[0]*10+s1[1];
	int sx=s2[0]*10+s2[1];
	if(sr==sx&&a[1]==1) a[2]=1;
	else a[2]=0;
	//两张车票对应的座位是否在同一节车厢的同一排
	int r=s1[2]-'A'+1;
	int x=s2[2]-'A'+1;
	if(a[2]==1){
		if(r>=4&&x>=4){
			a[3]=1;
			a[4]=1;		
		}
		else if(r<=3&&x<=3){
			a[3]=1;
			if(abs(r-x)==1) a[4]=1;
		}
		else{
			a[3]=0;
			a[4]=0;
		}
	}
	else{
		a[3]=0;
		a[4]=0;
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}
