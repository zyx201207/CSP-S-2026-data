#include<bits/stdc++.h>
using namespace std;
string a,b;
string as,bs;
bool lr(char a,char b){
	int cnt=a-1;
	cnt++;
	int cntb=b-1;
	cntb++;
	int t=cntb;
	if(cnt<cntb){
		cntb=cnt;
		cnt=t;
	}
	int ye=cnt-cntb;
	if(cnt==68&&cntb==67){
		return false;
	}else if(ye<=2){
		return true;
	}
	return false;
}
bool ne(char a,char b){
	int cnt=a-1;
	cnt++;
	int cntb=b-1;
	cntb++;
	int t=cntb;
	if(cnt<cntb){
		cntb=cnt;
		cnt=t;
	}
	int yee=cnt-cntb;
	if(cnt==68&&cntb==67){
		return false;
	}else if(cnt==70&&cntb==68){
		return true;
	}else{
		if((cnt-1)==cntb){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>as;
	cin>>b;
	cin>>bs;
	int flag=0,yflag=0;
	for(int i=0;i<2;i++){
		if(a[i]!=b[i]){
			flag=1;
			break;
		}
	}
	for(int i=0;i<2;i++){
		if(as[i]!=bs[i]){
			yflag=1;
		}
	}
	int va=0,vb=0,vc=0,vd=0;
	if(flag==1){
		cout<<"0000";
		return 0;
	}else{
		va=1;
		if(yflag==1){
		}else{
			vb=1;
			if(lr(as[2],bs[2])){
				vc=1;
				if(ne(as[2],bs[2])){
					vd=1;
				}
			}
		}
	}
	cout<<va<<vb<<vc<<vd;
	return 0;
}
