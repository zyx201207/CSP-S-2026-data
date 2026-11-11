#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	string c1,c2,s2,s1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2 ){
		cout<<"在同一节车厢"<<endl;
		if(s1==s2){
			cout<<"在同一节车厢的同一排"<<endl<<"在同一节车厢的同一排,且位于过道的同一侧"<<endl;
			cout<<"相邻";
		}
		else{
		cout<<"否在同一节车厢的同一排"<<endl;
			cout<<"否在同一节车厢的同一排,且位于过道的同一侧"<<endl;
			cout<<"否相邻";}
			
	}
	else{
		cout<<"否在同一节车厢";}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;

}
