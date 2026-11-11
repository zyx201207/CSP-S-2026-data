#include<bits/stdc++.h >
using namespace std;
int main(){
	long long a,b,f=-1,g=1000007,s=0,kl=1000070;
	int c[100007];
	cin>>a>>b;
	int se[b+5];
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int j=1;j<=b;j++){
		for(int k=1;k<=a;k++){
			if(f<c[k]&&c[k]<=g){
				if(c[k]==g){
					if(s==0){
						s++;
					}
					else{
						f=c[k];
					}
				}
				else{
					f=c[k];
				} 
	        }
		}
		g=f;
		se[j]=f;
		f=0;
		s=0;
		
	}
	for(int i=1;i<=b;i++){
		kl>se[i];
		kl=se[i];
	}
	cout<<kl;
}

