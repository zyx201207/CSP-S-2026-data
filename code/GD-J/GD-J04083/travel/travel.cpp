#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	int d1=0,d2=0,d3=0,d4=0;
	int a1=c2[2]-'0',a2=s2[2]-'0';
	int z;
	if(a1<a2){
		z=a1;
		a1=a2;
		a2=z;
	}
	for(int i=0;i<=1;i++){
		if(c1[i]==s1[i]){
			d1=1;
			if(c2[i]==s2[i]){
				d2=1;
			}
			else {
				d2=0;
				break;
			}
		}
		else{
			d1=0;
			d2=0;
			break;
		}
	}
	if(d1!=0){
		if(d2!=0){
			if(a1<=19&&a2>=17){
				d3=1;
				if(a1-a2==1){
					d4=1;
				}
			}
		}
	}
	if(d1!=0){
		if(d2!=0){
			if(a2>=20&&a1<=22){
				d3=1;
				d4=1;
			}
		}
	}
	cout<<d1<<d2<<d3<<d4;

	return 0;
} 
