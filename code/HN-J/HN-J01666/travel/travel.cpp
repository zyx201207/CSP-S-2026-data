#include<bits/stdc++.h>
using namespace std;
bool b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	/*
	int n;
	cin>>n;
	cout<<n;*/
	int c1,c2,z1,z2;
	char s1,s2;
	
	cin>>c1>>z1>>s1>>c2>>z2>>s2;
	/*
	cout<<c1<<endl<<c2<<endl<<s1<<endl<<s2<<endl<<z1<<endl<<z2;
	*/
	if(c1==c2){
		b[1]=1;
		if(z1==z2){
			b[2]=1;
			if(((s1>='A' && s1<='C') && (s2>='A' && s2<='C')) || ((s1>='D' && s1<='F') && (s2>='D' && s2<='F'))){
				b[3]=1;
				if(abs(s1-s2)==1){
					b[4]=1;
				}else{
					b[4]=0;
				}
			}else{
				b[3]=0;
			}
		}else{
			b[2]=0;
		}
	}else{
		b[1]=0;
	}
	for(int i=1;i<=4;i++){
		cout<<b[i];
	}
	return 0; 
}
