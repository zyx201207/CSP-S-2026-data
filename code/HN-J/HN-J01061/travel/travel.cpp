#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[10];
	int s=0,t=0;
	int x=0,y=0,m=0,n=0;
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}
	if(a[1]==a[6]&&a[2]==a[7]){
		x++;
		if(a[3]==a[8]&&a[4]==a[9]){
			y++;
			if(a[5]=='A'||a[5]=='B'||a[5]=='C') s=0;
	        else s=1;
	        if(a[10]=='A'||a[10]=='B'||a[10]=='C') t=0;
	        else t=1;
	        if(s==t){
		        m++;
		        if(s==1){
			        n++;
		        }
		        else if(s==0){
			        if(a[5]=='A'){
				        if(a[10]=='B') n++;
			        }
			        else if(a[5]=='B'){
				        if(a[10]=='A'||a[10]=='C'){
				  	        n++;
				        }
			        }
			        else if(a[5]=='C'){
				        if(a[10]=='B') n++;
			        }
		        }
	        }
		}
	}
	cout<<x<<y<<m<<n;
	return 0;
} 
