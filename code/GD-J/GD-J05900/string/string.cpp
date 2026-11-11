#include <bits/stdc++.h>
using namespace std;
long long tc(string a){
	long long b=0;
	int i=0;
	while(i<a.size()){
		b=b*10+a[i]-48;
		i++;
	}
	return b;
}
bool tc1(char a){
	if(a>='0'&&a<='9'){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	string a,t;
	char z,y;
	long long zuo,you,n,zi=0,yi,s=0;
	int xx;
	cin>>n;
	for(int i=0;i<n*2;i++){
		cin>>t;
		a+=t;
	}
	yi=a.size()-1;
	t="";
	while(tc1(a[zi])){
		t+=a[zi];
		zi++;
	}
	zuo=tc(t);
	z=a[zi];
	zi++;
	y=a[yi];
	yi--;
	xx=0;
	while(tc1(a[yi])){
		you=you+(a[yi]-48)*pow(10,xx);
		xx++;
		yi--;
	}
	while(zi<yi){
		
		if(z!=y){
			s+=min(zuo,you);
		}
		zuo-=min(zuo,you);
		you-=min(zuo,you);
		if(zuo!=0){
			y=a[yi];
			yi--;
			xx=0;
			while(tc1(a[yi])){
				you=you+(a[yi]-48)*pow(10,xx);
				xx++;
				yi--;
			}
		}else{
			t="";
			while(tc1(a[zi])){
				t+=a[zi];
				zi++;
			}
			zuo=tc(t);
			z=a[zi];
			zi++;
		}
	}
	if(z!=y){
		s+=min(zuo,you);
	}
	cout<<s;
}


