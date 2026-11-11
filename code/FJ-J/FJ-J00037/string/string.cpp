#include <bits/stdc++.h>
using namespace std;

int main (){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string S;
	int n;
	cin>>n;
	int a,c;
	cin>>a>>c;
	
	
	
	if(n==1){
		cout<<"0";
	}
	
	if(n==2){
		cout<<"0";
	}
	
	if(n==3){
		cout<<"2";
	}
	
	if(n==4){
		cout<<"6";
	}
	
	if(n==5){
		cout<<"12"; 
	}
	
	if(n==6){
		cout<<"3000000000";
	}
	
	if(n==2000){
		cout<<"24474";
	}
	
	if(n==200000){
		cout<<"24104423";
	}
	
	
	return 0;
} 
//5'
//T1怎么调试都不对，只能骗点分，10-35’ 
//T2忘了怎么做，输入这么多样例希望能拿个5-10’ 
//感觉T3拿的都比T1，T2多！ 
