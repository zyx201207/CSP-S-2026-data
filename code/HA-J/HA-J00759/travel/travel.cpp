#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	string c1,c2,c3,c4;
	char a[5],b[5];
	cin >> c1;
	for(int i=1;i<=3;i++){
		cin >> a[i];
	}
	int x=a[3]-0;
	cin >> c3;
	for(int i=1;i<=3;i++){
		cin >> b[i];
	}
	int y=b[3]-0;
	if(c1==c3){
		cout << 1;
	}else{
		cout << 0;
	}
	if(c1==c3&&a[1]==b[1]&&a[2]==b[2]){
		cout << 1;
	}else{
		cout << 0;
	}
	if(c1==c3&&a[1]==b[1]&&a[2]==b[2]&&(x+y<=132||x+y>=137)){
		cout << 1;
	}else{
		cout << 0;
	}
	if((a[1]==b[1]&&a[2]==b[2])&&(x+y<=132||x+y>=137)&&(x-y==1||y-x==1)&&(x+y<133||x+y>136)){
		cout << 1;
	}else{
		cout << 0;
	}
	
	return 0;
} 
