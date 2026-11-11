#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a>>b  >> c >> d;
	if(a==c){
		cout << "1";
		
	}else{
		cout <<"0000";
		return 0;
	}
	int sum1=0,sum2=0;
	for(int i = 0;i<b.length()-1;i++){
		sum1*=10;
		sum1+=int(b[i]-'0');
	}
	for(int i = 0;i<d.length()-1;i++){
		sum2*=10;
		sum2+=int(d[i]-'0');
	}
	if(sum1==sum2){
		cout <<"1";
	}else{
		cout << 0;
	}
	if(sum1==sum2 && ((b[b.length()-1]<='C' && d[d.length()-1]<='C')||(b[b.length()-1]>='D' && d[d.length()-1]>='D'))){
		cout <<"1";
	}else{
		cout << 0;
	}
	if(sum1==sum2){
		if((b[b.length()-1]==d[d.length()-1]+1 || b[b.length()-1]+1==d[d.length()-1]) && ((b[b.length()-1]!='C' && d[d.length()-1]!='D')&&(b[b.length()-1]!='D' && d[d.length()-1]!='C'))){
			cout <<"1";
		}else{
			cout << 0;
		}
	}else if (b[b.length()-1]==d[d.length()-1]){
		if(sum1==sum2+1 ||sum1+1==sum2){
			cout <<"1";
		}else{
			cout <<0;
		}
	}else{
		cout << 0;
	}
	
}
