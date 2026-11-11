//GZ-J00450 杨永虔 弘毅中学 
#include<bits/stdc++.h>
using namespace std;

char seat1[2];
char seat2[3];
char seat3[2];
char seat4[3];
char travel[4];
    
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>seat1[0]>>seat1[1];
	cin>>seat2[0]>>seat2[1]>>seat3[2];
	cin>>seat3[0]>>seat3[1];
	cin>>seat4[0]>>seat4[1]>>seat4[3];
	//输入字符 

	if(seat1[0]!=seat3[0]||seat1[1]!=seat3[1]){
		cout<<"0000";
		return 0;
	}//travel[0]='1';
	//特判不是同一车厢 
	
	if(seat2[0]!=seat4[0]||seat2[1]!=seat4[1]){
		cout<<"1000";
		return 0;
	}//travel[1]='1';
	//特判不是同一列 
	
	int r1,r2;
	if(seat2[3]>='A'&&seat2[3]<='C')r1=seat2[3]-'A';
	if(seat4[3]>='A'&&seat4[3]<='C')r2=seat4[3]-'A';
   // cout<<r1<<" "<<r2<<endl; 
	
    if(seat2[3]=='D'||seat2[3]=='F')r1=4;
	if(seat4[3]=='D'||seat4[3]=='F')r2=4;

	//以常数代替字符
	if((r1!=4&&r2==4)||(r1==4&&r2!=4)) {
		cout<<"1100";
		return 0;
	}
	//特判不在同一边 
	
	
	if(r1<3&&r2<3){

		
		
		if(r1!=(r2-1)&&(r1-1)!=r2){
			cout<<"1110";
			return 0;
		}//特判不相邻 
		cout<<"1111";
		//特判相邻 

	} //特判同一边 
	
	if(r1==4&&r2==4){
		cout<<"1111";
		return 0;
	}
	//特判DF座位 


	
	
	return 0;
} 
