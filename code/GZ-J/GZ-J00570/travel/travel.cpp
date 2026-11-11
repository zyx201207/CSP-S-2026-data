#include<bits/stdc++.h>
using namespace std;
long long st_t(string s){
	long long r=1;
	long long ans=0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]-'0'<10){
			ans+=(s[i]-'0')*r;
		}else{
			ans+=r*(s[i]-'A'+10);	
		}
		r*=16;
		
	}
	
	return ans;
}
int f(char x,char y){
	if(x=='A' && y=='B' || x=='B' && y=='A' ){
		return 1;
	}
	else if(x=='B' && y=='A' || x=='B' && y=='C'){
		return 1;
	}
	else if(x=='A' && y=='B' || x=='C' && y=='B'){
		return 1;
	}
	else if(x=='D' && y=='F' || x=='F' && y=='D'){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
//	GZ-J00570 遵义市第十二中学  喻思豪 
	freopen("trafel.in","r",stdin);
	freopen("trafel.out","w",stdout);
	string c1,c3,c2,c4;
	cin>>c1>>c2>>c3>>c4;
	int m1=st_t(c1),m2=st_t(c3);
	char x=c2[2],y=c4[2];
	if(m1==m2){
		cout<<"1";
		
		int s1=st_t(c2.erase(2,1)),s2=st_t(c4.erase(2,1));
		if(s1==s2){
			cout<<"1";
			int n1=x-'0',n2=y-'0';
			if(n1<=67 && n2<=67 || n1>67 && n2>67){
				cout<<"1";
				cout<<f(x,y);
				
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	} 
	else{
		cout<<"0000";
		return 0;
	}
//	int c1,c2;
//	cin>>c1>>c2;
//	cout<<f(c1,c2);
	return 0;
} 
