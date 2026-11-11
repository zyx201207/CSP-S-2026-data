#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int s[10],s1[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	for(int i=1;i<=2;++i){
		s[i]=a[i-1];
	}
	for(int i=1;i<=2;++i){
		s1[i]=b[i-1];
	}
	bool flag=true;
	for(int i=1;i<=2;++i){
		if(s[i]!=s1[i]){
			flag=false;
		}
	}
	if(!flag){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int ahang1=a1[0]-'0';
	int ahang2=a1[1]-'0';
	int bhang1=b1[0]-'0';
	int bhang2=b1[1]-'0';
	if(ahang1==bhang1&&ahang2==bhang2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char azuo=a1[2];
	char bzuo=b1[2];
	if(azuo=='A'){
		if(bzuo=='B'){
			cout<<"11";
		}if(bzuo=='C'){
			cout<<"10";
		}if(bzuo=='D'){
			cout<<"00";
		}if(bzuo=='F'){
			cout<<"00";
		}
	}if(azuo=='B'){
		if(bzuo=='A'){
			cout<<"11";
		}if(bzuo=='C'){
			cout<<"11";
		}if(bzuo=='D'){
			cout<<"00";
		}if(bzuo=='F'){
			cout<<"00";
		}
	}if(azuo=='C'){
		if(bzuo=='B'){
			cout<<"11";
		}if(bzuo=='A'){
			cout<<"10";
		}if(bzuo=='D'){
			cout<<"00";
		}if(bzuo=='F'){
			cout<<"00";
		}
	}if(azuo=='D'){
		if(bzuo=='A'){
			cout<<"00";
		}if(bzuo=='C'){
			cout<<"00";
		}if(bzuo=='B'){
			cout<<"00";
		}if(bzuo=='F'){
			cout<<"11";
		}
	}if(azuo=='F'){
		if(bzuo=='A'){
			cout<<"00";
		}if(bzuo=='B'){
			cout<<"00";
		}if(bzuo=='C'){
			cout<<"00";
		}if(bzuo=='D'){
			cout<<"11";
		}
	}
	return 0;
}
