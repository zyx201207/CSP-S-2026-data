#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int cnt1,cnt2;
int sum1,sum2;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	int num4=a.size();
	for(int i=0;i<num4;i++){
		cnt1*=10;
		cnt1+=(a[i]-'0'); 
	}
	int num3=c.size();
	for(int i=0;i<num3;i++){
		cnt2*=10;
		cnt2+=(c[i]-'0'); 
	}
	int num1=b.size()-1;
	x=b[num1];
	int num2=d.size()-1;
	y=d[num2];
	for(int i=0;i<num1;i++){
		sum1*=10;
		sum1+=(b[i]-'0');
	}
	for(int i=0;i<num2;i++){
		sum2*=10;
		sum2+=(d[i]-'0');
	}
	if(cnt1==cnt2){
		cout<<1;
		if(sum2==sum1){
			cout<<1;
			if((x=='D'&&y=='F')||(x=='F'&&y=='D')){
				cout<<1;
				if((x=='D'&&y=='F')||(x=='F'&&y=='D')){
					cout<<1;
				}else if(x=='D'||y=='D'||x=='F'||y=='F'){
					cout<<0;
				}else if(abs(x-y)==1){
					cout<<1;
				}else {
					cout<<0;
				}
			}else if(x=='D'||y=='D'||x=='F'||y=='F'){
				cout<<0<<0;
			}else{
				cout<<1;
				if((x=='D'&&y=='F')||(x=='F'&&y=='D')){
					cout<<1;
				}else if(x=='D'||y=='D'||x=='F'||y=='F'){
					cout<<0;
				}else if(abs(x-y)==1){
					cout<<1;
				}else {
					cout<<0;
				}
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
