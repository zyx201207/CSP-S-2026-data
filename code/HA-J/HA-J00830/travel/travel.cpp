#include<bits/stdc++.h>
using namespace std;
struct travel{
	string chexiang;
	string zuowei;
};
travel tong[5];
int main(){
	freopen("travel.in ","r",stdin);
	freopen("travel.out","w",stdout);
char A,B,C,D,F;
int sum=0;
	cin>>tong[0].chexiang>>tong[0].zuowei>>tong[1].chexiang>>tong[1].zuowei;
	if(tong[0].chexiang==tong[1].chexiang)
		cout<<"1";
	else
		cout<<"0";
	if(tong[0].zuowei[0]==tong[1].zuowei[0]&&tong[0].zuowei[1]==tong[1].zuowei[1]&&tong[0].chexiang==tong[1].chexiang)
		cout<<"1";
	else
		cout<<"0";
	int n=0,m=0,j=0,g=0;
	if(tong[0].zuowei[0]==tong[1].zuowei[0]&&tong[0].zuowei[1]==tong[1].zuowei[1]&&tong[0].chexiang==tong[1].chexiang){
		if(tong[0].zuowei[2]=='A'||tong[0].zuowei[2]=='B'||tong[0].zuowei[2]=='C')
			n=n+1;
		if(tong[1].zuowei[2]=='A'||tong[1].zuowei[2]=='B'||tong[1].zuowei[2]=='C')
			m=m+1;
		if(tong[0].zuowei[2]=='F'||tong[0].zuowei[2]=='D')
			j=j+1;
		if(tong[0].zuowei[2]=='F'||tong[0].zuowei[2]=='D')
			g=g+1;
		if(n==1&&m==1)
			cout<<"1";
		else if(j==1&&g==1)
			cout<<"1";
		else cout<<"0";
		if(n==1&&m==1||j==1&&g==1)
		sum=1;
		
	}
	else 
			cout<<"0";
	if(tong[0].zuowei[0]==tong[1].zuowei[0]&&tong[0].zuowei[1]==tong[1].zuowei[1]&&tong[0].chexiang==tong[1].chexiang&&sum==1){
		if(tong[0].zuowei[2]=='A'&&tong[1].zuowei[2]=='B')
			cout<<"1";
		else if(tong[0].zuowei[2]=='B'&&tong[1].zuowei[2]=='C')
			cout<<"1";
		else if(tong[1].zuowei[2]=='A'&&tong[0].zuowei[2]=='B')
			cout<<"1";
		else if(tong[1].zuowei[2]=='B'&&tong[0].zuowei[2]=='C')
			cout<<"1";
		else if(tong[0].zuowei[2]=='F'&&tong[1].zuowei[2]=='D')
			cout<<"1";
		else if(tong[1].zuowei[2]=='F'&&tong[0].zuowei[2]=='D')
			cout<<"1";
		else 
			cout<<"0";
		
	}
	else 
		cout<<"0";
	return 0;
}
