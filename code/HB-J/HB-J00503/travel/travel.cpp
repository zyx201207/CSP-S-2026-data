#include<bits/stdc++.h>
using namespace std;
char a[35];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%[^\n]",a);
	int s1=0,s2=0;
	s1+=a[0]-'0';
	s1*=10;
	s1+=a[1]-'0';
	s2+=a[7]-'0';
	s2*=10;
	s2+=a[8]-'0';
	if(s2!=s1){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		int s3=0,s4=0;
		s3+=a[3]-'0';
		s3*=10;
		s3+=a[4]-'0';
		s4+=a[10]-'0';
		s4*=10;
		s4+=a[11]-'0';
		if(s3!=s4){
			cout<<"000";
			return 0;
		}
		else{
			cout<<1;
			int s5=a[5]-'A'+1;
			int s6=a[12]-'A'+1;
			if(s5>=4&&s6>=4) cout<<1;
			else if(s5<4&&s6<4) cout<<1;
			else{
				cout<<"00";
				return 0;
			}
			if(abs(s5-s6)==1) cout<<1;
			else cout<<0;
		}
	}
	return 0;
}
