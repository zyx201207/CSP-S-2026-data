#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2,x1,y1;
	int a[4]={0,0,0,0};
	cin>>c1>>s1>>c2>>s2;
	char c=s1[2],d=s2[2];;
	for(int i=0;i<2;i++){
		x1+=s1[i];
	}
	for(int i=0;i<2;i++){
		y1+=s2[i];
	}
	if(c1==c2){
		a[0]=1;
	}else{
		a[0]=0;
	}
	if(x1==y1){
		a[1]=1;
	}else if(c1!=c2||x1!=y1){
		a[1]=0;
	}else{
		a[1]=0;
	}
	if(c==d-1||c==d+1||c==d-2||c==d+2){
		a[2]=1;
	}else{
		a[2]=0;
	}
	if(a[1]==0) a[2]=0;
	if(c=='C'&&d=='D'||c=='D'&&d=='C') a[2]=0;
	if(c=='A'&&d=='B'||c=='B'&&d=='A'||c=='B'&&d=='C'||c=='C'&&d=='B'||c=='D'&&d=='F'||c=='F'&&d=='D'){	
		a[3]=1;
	}else{
		a[3]=0;
	}
	if(a[2]==0) a[3]=0;
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0;
}
