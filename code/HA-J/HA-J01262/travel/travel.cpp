#include<bits/stdc++.h> 
using namespace std;
struct po{
	string a;
	string b;
	int c;
	};
	int one,two,three,four;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	po R,X;
	cin>>R.a>>R.b>>X.a>>X.b; 
	
	if(R.b[2]=='D'||R.b[2]=='F')
	R.c=1;
	else
	R.c=0;
	
	if(X.b[2]=='D'||X.b[2]=='F')
	X.c=1;
	else
	X.c=0;
	
	if(R.a==X.a)
	one=1;	
	
	if(one==1&&R.b[0]==X.b[0]&&R.b[1]==X.b[1])
	two=1;
	
	if(X.c==R.c&&two==1){
		three=1;
		if(X.b[2]-1==R.b[2]||X.b[2]+1==R.b[2]){
		four=1;
		}	
	}
	printf("%d%d%d%d",one,two,three,four);
	return 0;
}
