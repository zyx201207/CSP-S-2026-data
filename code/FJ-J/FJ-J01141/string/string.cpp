#include<iostream>
using namespace std;
long long b[2830231];
char c[2884031];
char t[2003023];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	long long l=0;
	long long s=0,x=0,gs=0;
	for(int i=1;i<=a;i++){
		cin>>b[i]>>c[i];
		gs+=b[i];
		for(int j=1;j<=b[i];j++){
			t[l+j]=c[i];
		}
		l+=b[i];
	}
	for(int i=1;i<=gs/2;i++){
		if(t[i]!=t[gs+1-i]){
			s++;
		}
	}
		

	cout<<min(s,gs-s);
	return 0;
}
