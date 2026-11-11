#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,a3,a4;
	cin>>a1;
	cin>>a2>>a3>>a4;
	int b1=0,b2=0;//³µÏá 
	int k=1;
	//×Ö·û×ª»»Êý×Ö 
	for(int i=a1.size()-1;i>=0;i--){
		if(a1[i]>='1'&&a1[i]<'9'){
			b1+=((a1[i]-'0')*k);
			k*=10;
		}
		else break;
	}
	k=1;
	int c1,c2;//ÅÅ 
	char d1,d2;//Î» 
	d1=a2[a2.size()-1];
	for(int i=a2.size()-2;i>=0;i--){
		if(a2[i]>='1'&&a2[i]<'9'){
			c1+=((a1[i]-'0')*k);
			k*=10;
		}
		else break;
	}
	
	
	//×Ö·û×ª»»Êý×Ö 
	for(int i=a3.size()-1;i>=0;i--){
		if(a3[i]>='1'&&a3[i]<'9'){
			b1+=((a1[i]-'0')*k);
			k*=10;
		}
		else break;
	}
	k=1; 
	d2=a4[a4.size()-1];
	for(int i=a4.size()-2;i>=0;i--){
		if(a4[i]>='1'&&a4[i]<'9'){
			c2+=((a1[i]-'0')*k);
			k*=10;
		}
		else break;
	}
	
	//ÅÐ¶Ï
	if(a1==a3){
		cout<<"1";
	}
	else if(a1!=a2){
		cout<<"0";
	}
	//else {
	//	cout<<"0"<<endl;
	//	cout<<"0"<<endl;
	//	cout<<"0"<<endl;
	//	cout<<"0"<<endl;
	//	return 0;
	//}
	cout<<endl;
	if(c1==c2){
		cout<<"1";
	}
	else {
	cout<<"0"<<endl;	
	cout<<"0"<<endl;
	cout<<"0"<<endl;
	return 0;
	}
	cout<<endl;
	if(((d1-'A'+1)<4&&(d2-'A'+1)<4)||((d1-'A'+1)>=4&&(d2-'A'+1)>=4)){
		cout<<"1";
	}
	else {
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		return 0;
	}
	cout<<endl;
	bool f=true;
	if((d1=='C'&&d2=='D')||(d2=='C'&&d1=='D')){
		f=false;
		cout<<"0"<<endl;
	}
	if(((d1-'A'+1)+1==(d2-'A'+1))||((d1-'A'+1)-1==(d2-'A'+1))){
		if(f)
		cout<<"1";
	}
	else cout<<"0";
	cout<<endl;
	fclose("travel.in");
	fclose("travel.out");
	return 0;
} 
