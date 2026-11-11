#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		string pai1,pai2;
		char z1,z2;
		cout<<'1';
		for(int i=0;i<3;i++){
			if(s1[i]>='0'&&s1[i]<='9'){
				pai1+=s1[i];
			}else{
				z1=s1[i];
			}
		}
		for(int i=0;i<3;i++){
			if(s2[i]>='0'&&s2[i]<='9'){
				pai2+=s2[i];
			}else{
				z2=s2[i];
			}
		}
		if(pai1==pai2){
			cout<<'1';
		}else{
			cout<<'0';
		}
		if((z1<='C'&&z2<='C')&&(pai1==pai2)||(z1>='D'&&z2>='D')&&(pai1==pai2)){
			cout<<'1';
		}else{
			cout<<'0';
		}
		int a[3],b[3];
		for(int i=0;i<pai1.size();i++){
			a[i]=pai1[i]-'0';
		}
		for(int i=0;i<pai1.size();i++){
			b[i]=pai2[i]-'0';
		}
		int sz1=a[0]*10+a[1];
		int sz2=b[0]*10+b[1];
		if(z1=='A'){
			if(sz1==1){
				if((sz2==sz1+1&&z2=='A')||(sz2==sz1&&z2=='B')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if(sz1==18){
				if((sz2==sz1-1&&z2=='A')||(sz2==sz1&&z2=='B')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				if((sz2==sz1-1&&z2=='A')||(sz2==sz1+1&&z2=='A')||(sz2==sz1&&z2=='B')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}
		}
		else if(z1=='B'){
			if(sz1==1){
				if((sz2==sz1+1&&z2=='B')||(sz2==sz1&&z2=='A')||(sz2==sz1&&z2=='C')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if(sz1==18){
				if((sz2==sz1-1&&z2=='B')||(sz2==sz1&&z2=='A')||(sz2==sz1&&z2=='C')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				if((sz2==sz1-1&&z2=='B')||(sz2==sz1+1&&z2=='B')||(sz2==sz1&&z2=='A')||(sz2==sz1&&z2=='C')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}
		}
		else if(z1=='C'){
			if(sz1==1){
				if((sz2==sz1+1&&z2=='C')||(sz2==sz1&&z2=='B')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if(sz1==18){
				if((sz2==sz1-1&&z2=='C')||(sz2==sz1&&z2=='B')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				if((sz2==sz1-1&&z2=='C')||(sz2==sz1+1&&z2=='C')||(sz2==sz1&&z2=='B')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}
		}
		else if(z1='D'){
			if(sz1==1){
				if((sz2==sz1+1&&z2=='D')||(sz2==sz1&&z2=='F')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if(sz1==18){
				if((sz2==sz1-1&&z2=='D')||(sz2==sz1&&z2=='F')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				if((sz2==sz1-1&&z2=='D')||(sz2==sz1+1&&z2=='D')||(sz2==sz1&&z2=='F')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}
		}
		else{
			if(sz1==1){
				if((sz2==sz1+1&&z2=='F')||(sz2==sz1&&z2=='D')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if(sz1==18){
				if((sz2==sz1-1&&z2=='F')||(sz2==sz1&&z2=='D')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				if((sz2==sz1-1&&z2=='F')||(sz2==sz1+1&&z2=='F')||(sz2==sz1&&z2=='D')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
