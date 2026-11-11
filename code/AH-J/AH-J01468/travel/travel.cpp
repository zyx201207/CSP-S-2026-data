#include<iostream>
#include<cstdio>
using namespace std;
string c1,c2;
string s1,s2;
string ans;
int ccc;
bool check(char x,char y){
    if(x=='A'&&y=='B'||x=='B'&&y=='C'||x=='D'&&y=='F') return true;
    if(x=='B'&&y=='A'||x=='C'&&y=='B'||x=='F'&&y=='D') return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string p1=s1.substr(0,2);
    string p2=s2.substr(0,2);
    char t1=s1[2],t2=s2[2];
    if(c1==c2){
		cout<<1;
		if(p1==p2){
			cout<<1;
			if(t1=='A'||t1=='B'||t1=='C') ccc++;
            if(t2=='A'||t2=='B'||t2=='C') ccc++;
            if(ccc==0||ccc==2){
				cout<<1;
				if(check(t1,t2)){
					cout<<1;
				}else{
					cout<<0;
				}
            }else{
				cout<<"00";
            }
		}else{
			cout<<"000";
		}
    }else{
		cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
