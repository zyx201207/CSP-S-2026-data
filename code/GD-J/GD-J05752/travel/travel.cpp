#include<bits/stdc++.h>
using namespace std;
	string c1,s1,c2,s2;
int main(){

	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else cout<<0;//第一次输出
	string d1;
	d1=s1[0]+s1[1];
	string d2;
	d2=s2[0]+s2[1];
	if(c1==c2){
		if(d1==d2){
			cout<<1;
			
		}
	}
	else cout<<0;//第二次输出
	
	int w1=0,w2=0;
		if('D'==s1[2]||'F'==s1[2]){
		w1=0;
	}else w1=1;
	if(s1[1]=='A'){
		w1=1;
	}
	if('D'==s2[2]||'F'==s2[2]){
		w2=0;
	}else w2=1;
	if(s2[2]=='A'){
		w2=1;
	}
	if(c1==c2){
		if(d1==d2){
	
			if(w1==w2){
				cout<<1;
			}else cout<<0;
		}
	}//第三次 
	if(c1==c2){
		if(d1==d2){
			if(w1==0&&w2==0){
				cout<<1;
				return 0;
			}else
				if(w1==1&&w2==1){
					if(abs(s1[2]-s2[2])==1){
						cout<<1;
						return 0;
					}
				}
		}
	}
	cout<<0;
	return 0;
}
