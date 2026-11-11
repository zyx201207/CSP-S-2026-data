#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
long long r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	long long i=0,j=0;
	if(r1[0]=='0'){
		r=r1[1]-'0';
	}else{
		r+=10;
		r+=r1[1]-'0';
	}
	if(x1[0]=='0'){
		x=x1[1]-'0';
	}else{
		x+=10;
		x+=x1[1]-'0';
	}
	if(r2[0]=='0'){
		i=1;
	}
	if(x2[0]=='0'){
		j=1;
	}
	//while(1){
	//	if(r1[i]!='0'){
	//		break;
	//	}
	//	i++;
	//}
	if(r==x){
		cout<<1;
		if(r2[i]==x2[j]){
			cout<<1;
			if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'){
				if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'){
					cout<<1;
					if(r2[2]-x2[2]==1||r2[2]-x2[2]==-1){
						cout<<1;
					}else{
						cout<<0;
					}
				}else{
					cout<<"00";
				}
			}else{
				if(x2[2]=='D'||x2[2]=='F'){
					cout<<1;
					cout<<1;
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
