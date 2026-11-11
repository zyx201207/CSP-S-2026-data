#include<bits/stdc++.h>
using namespace std;
char s[10]={'A','B','C','D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char c[4],d[4];
	cin>>a;
	for(int i=0;i<3;i++){
		cin>>c[i];
	}
	cin>>b;
	for(int i=0;i<3;i++){
		cin>>d[i];
	}
	if(a==b){
		cout<<"1";
		int c2,d2;
		c2=(c[0]+c[1])-'0';
		d2=(d[0]+d[1])-'0';
		if(c2==d2){
			cout<<"1";
			int c3,d3;
			for(int i=0;i<5;i++){
				if(c[2]==s[i]){
					c3=i;
				}
				if(d[2]==s[i]){
					d3=i;
				}
			}
			if(c3<=2&&d3<=2){
				cout<<"1";
				int maxn=max(c3,d3);
				int minn=min(c3,d3);
				if(maxn-minn==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(c3>2&&d3>2){
				cout<<"1";
				cout<<"1";
			}
			else{
				cout<<"0"<<"0";
			}
		}
		else{
			cout<<"0"<<"0"<<"0";
		}
	}
	else{
		cout<<"0"<<"0"<<"0"<<"0";
	}
	return 0;
}
