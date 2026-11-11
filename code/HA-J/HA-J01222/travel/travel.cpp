#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char aa[3],bb[3];
	cin>>a;
	for(int i=1;i<=3;i++){
		cin>>aa[i];
	}
	cin>>b;
	for(int i=1;i<=3;i++){
		cin>>bb[i];
	}
	int f1=0,f2=0,f3=0;
	if(a==b){
		cout<<1;
		f1++;
	}else{
		cout<<0;
	}
	if(f1!=0&&aa[1]==bb[1]&&aa[2]==bb[2]){
		cout<<1;
		f2++;
	}else{
		cout<<0;
	}
	if(f2!=0&&aa[3]<='C'&&bb[3]<='C'||f2!=0&&aa[3]>'C'&&bb[3]>'C'){
		cout<<1;
		f3++;
	}else{
		cout<<0;
	}
	if(f3!=0&&aa[3]==bb[3]-1||f3!=0&&aa[3]==bb[3]+1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
