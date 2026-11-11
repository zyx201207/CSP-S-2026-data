#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long sum1,sum2,sum;
bool y=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	sum1=c1[0]-'0'+c1[1]-'0';
	sum2=c2[0]-'0'+c2[1]-'0';
	if(sum1==sum2){
		cout<<y;
	}
	else{
		y=0;
		cout<<y;
	}
	sum1=s1[0]-'0'+s1[1]-'0';
	sum2=s2[0]-'0'+s2[1]-'0';
	if(sum1==sum2&&y){
		cout<<y;
	}
	else{
		y=0;
		cout<<y;
	}
	sum1=s1[2]-'A';
	sum2=s2[2]-'A';
	if(sum1>=0&&sum1<=2&&sum2>=0&&sum2<=2&&y){
		cout<<1;
	}
	else if(sum1>=3&&sum1<=4&&sum2>=3&&sum2<=4&&y){
		cout<<1<<1;
		return 0;
	}
	else{
		y=0;
		cout<<0;
	}
	sum=sum1-sum2;
	if(sum<0)sum=-sum;
	if(sum==1&&sum1!=3&&sum2!=3&&sum1!=4&&sum2!=4&&y){
		cout<<1;
		return 0;
	}
	else{
		y=0;
		cout<<0;
	}
    return 0;
}
