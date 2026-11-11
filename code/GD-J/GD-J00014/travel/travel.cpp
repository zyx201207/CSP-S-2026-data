#include<bits/stdc++.h>
using namespace std;
char a[11];
bool m=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9]>>a[10];
	if(a[1]==a[6]&&a[2]==a[7])cout<<1;
	else cout<<0;
	if((a[1]==a[6]&&a[2]==a[7])&&(a[3]==a[8]&&a[4]==a[9])){
		cout<<1;
	}
	else cout<<0;
	if((a[1]==a[6]&&a[2]==a[7])&&(a[3]==a[8]&&a[4]==a[9])&&((a[5]<='C'&&a[10]<='C')||(a[5]>='D'&&a[10]>='D'))){
		cout<<1;
		m=1;
	}
	else cout<<0;
	if(m&&abs(a[5]-a[10])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
