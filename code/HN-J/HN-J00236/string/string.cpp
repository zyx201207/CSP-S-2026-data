#include<iostream>
using namespace std;
const long N=1e9+5;
char s[N];
int n=0,num1=0;//段数及每段长度
char c;
int sav=0,num2=0; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;//我知道会超时，但我想不到更好的方法了 
	for(int i=0;i<n;i++){
		cin>>num1>>c;
		for(int j=0;j<num1;j++){
			s[sav+j]=c;
		}
		sav+=num1;
	}
	for(int i=0;i<sav/2;i++){
		if(s[i]!=s[sav-i-1]){
			num2++;
		}
	}
	cout<<num2;
	return 0;
}
