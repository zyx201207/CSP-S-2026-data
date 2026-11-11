//马辰一帆 GZ-J00578 贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
int a,b,n,g,alen;
char c;
string stra,strb,strc;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g>>c;
		for(int j=1;j<=g;j++){
			stra+=c;
		}
	}
	strb=stra,strc=stra;
	alen=stra.size();
	for(int i=alen/2;i<alen;i++){
		if(strb[i]!=strb[alen-i-1]){
			a++;
			strb[i]=strb[alen-i-1];
		}
	}
	for(int i=0;i<alen/2;i++){
		if(strc[i]!=strc[alen-i-1]){
			b++;
			strb[i]=strb[alen-i-1];
		}
	}
	cout<<min(a,b);
	return 0;
} 
//hymmyyds 
