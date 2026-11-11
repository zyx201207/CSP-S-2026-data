#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int c11=(c1[0]-'0')*10+c1[1]-'0';
	int s11=(s1[0]-'0')*10+s1[1]-'0';
	int c22=(c2[0]-'0')*10+c2[1]-'0';
	int s22=(s2[0]-'0')*10+s2[1]-'0';
	if(c11==c22)cout<<"1";
	else{
		cout<<"0000";
		return 0; 
	}
	if(s11==s22)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	int posi1=s1[2]-'A',posi2=s2[2]-'A';
	//cout<<(posi1<=2&&posi1<=2);
	//cout<<posi1<<" "<<posi2;
	if(posi1<=2&&posi2<=2){
		cout<<"1";
		if(abs(posi1-posi2)==1){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if(posi1>2&&posi2>2){
		cout<<"11";
	}else{
		cout<<"00";
	}
	//cout<<endl;
	//cout<<c11<<" "<<c22<<" "<<s11<<" "<<s22<<" "<<posi1<<" "<<posi2<<endl;
	//cout<<((posi1<=2&&posi2<=2)||(posi1>2&&posi2>2))<<endl;
	return 0;

}

