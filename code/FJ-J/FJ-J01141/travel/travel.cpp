#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int a1,b1,c1,d1;//che wei che wei
	int s,f;//weilie
	a1=(a[0]-'0')*10+(a[1]-'0');
	b1=(b[0]-'0')*10+(b[1]-'0');
	c1=(c[0]-'0')*10+(c[1]-'0');
	d1=(d[0]-'0')*10+(d[1]-'0');
	s=(b[2]-'A')+1;
	f=(d[2]-'A')+1;
	cout<<(a1==c1);
	if(a1!=c1){
		cout<<0<<0<<0;
		return 0;
	}
	int o=0;
	cout<<(b1==d1);
	if(s<=3){
		cout<<(f<=3&&b1==d1);
		if(!(f<=3)){
			o++;
		}
	}else{
		cout<<(f>3&&b1==d1);
		if(!(f>3)){
			o++;
		}
	}
	if(o==0){
		cout<<(((abs(s-f))+(abs(b1-d1)))<=1);
	}else{
		cout<<0;
	}
	
	return 0;
}
