#include <bits/stdc++.h>
using namespace std;




bool cccc(string a,string b){
	char ch1=a[2],ch2=b[2];
	if('A'<=ch1&&ch1<='C'&&'A'<=ch2&&ch2<='C'){
		return true;
	}else if( (ch1=='D'&&ch2=='F')||(ch1=='F'&&ch2=='D') ){
		return true;
	}
	return false;
}
bool cccc2(string a,string b){
	char ch1=a[2],ch2=b[2];
	int t=min(ch1-'A',ch2-'A');
	int t2=max(ch1-'A',ch2-'A');
	ch1=t+'A';
	ch2=t2+'A';
	if(ch1=='D'){
		return true;
	}else{
		if(ch1=='A'&&ch2=='B') return true;
		if(ch1=='B'&&ch2=='C') return true;
	}
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cc1,ss1,cc2,ss2;
	cin>>cc1>>ss1>>cc2>>ss2;
	int ans1=0,ans2=0,ans3=0,ans4=0;
	if(cc1==cc2){
		ans1=1;
	}else{
		cout<<ans1<<ans2<<ans3<<ans4;
		return 0;
	}
	if(ss1[0]==ss2[0]&&ss1[1]==ss2[1]){
		ans2=1;
	}else{
		cout<<ans1<<ans2<<ans3<<ans4;
		return 0;
	}
	if(cccc(ss1,ss2)){
		ans3=1;
	}else{
		cout<<ans1<<ans2<<ans3<<ans4;
		return 0;
	}
	if(cccc2(ss1,ss2)){
		ans4=1;
	}else{
		cout<<ans1<<ans2<<ans3<<ans4;
		return 0;
	}	
	
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}











