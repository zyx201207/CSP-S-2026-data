#include<bits/stdc++.h>
using namespace std;
int a;
bool e=true;
struct node{
	long long x;
	char c;
};
node z[10000005];
string l,r,y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	long long s=0;
	cin>>z[0].x>>z[0].c;
	char t=z[0].c;
	for(int i=1;i<=a-1;i++){
		cin>>z[i].x>>z[i].c;
		if(z[i].c!=t)e=false;
		/*for(long long j=1;j<=z[i].x;j++){
			y+=z[i].c;
		}*/
	}
	if(e){
		cout<<"0"<<endl;
		return 0;
	}
	else{
		long long q=a-1;
		for(int i=0;i<a/2;i++){
			if(z[i].c!=z[q].c){
				if(z[i].x<z[q].x)s+=z[i].x;
				else s+=z[q].x;
			}
			else{
				if(z[i].x<z[q].x)s+=z[q].x-z[i].x;
				else s+=z[i].x-z[q].x;
			}
			q--;
		}
	}
	cout<<s<<endl;
	return 0;
}
