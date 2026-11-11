#include <bits/stdc++.h>
using namespace std;
long long n,i,j,k,x,y,m;
string sa,sb,sc,sd;
string paia,paib;
char zuoa,zuob;
bool fa,fb,fc,fd;
bool pan(char c){
	if(c=='A'||c=='B'||c=='C'){
		return 0;
	}
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa>>sb>>sc>>sd;
	if(sa!=sc){
		fa=fb=fc=fd=0;
	}
	else{
		fa=1;
		paia=sb[0]+sb[1];
		paib=sd[0]+sd[1];
		if(paia!=paib){
			fb=fc=fd=0;
		}
		else{
			fb=1;
			zuoa=sb[2];
			zuob=sd[2];
			if(pan(zuoa)!=pan(zuob)){
				fc=fd=0;
			}
			else{
				fc=1;
				if(zuoa>zuob){
					swap(zuoa,zuob);
					
				}
				if((zuoa=='A'&&zuob=='B')||(zuoa=='B'&&zuob=='C')||(zuoa=='D'&&zuob=='E')){
						fd=1;
					}
					else{
						fd=0;
					}
			}
		}
	}
	cout<<fa<<fb<<fc<<fd;
	return 0;
} 
