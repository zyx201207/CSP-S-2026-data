#include<bits/stdc++.h>
using namespace std;
char x,s[1111],ss[7]={0,'A','B','C','D','E'};
int z,c,a[111],b[111],zz,cc;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	for(int i=1;i<=2;i++){
		cin>>x;
		z=x-'0';
		a[i]=a[i]+z*10;
		cin>>x;
		a[i]=a[i]+x-'0';
		
		cin>>x;
		z=x-'0';
		b[i]=b[i]+z*10;
		cin>>x;
		b[i]=b[i]+x-'0';
		cin>>s[i];
	}
	if(a[1]!=a[2]){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		if(b[1]!=b[2]){
			cout<<"000";
		}
		else{
			cout<<1;
			for(int i=1;i<=5;i++){
				if(s[1]==ss[i]){
					z=i;
					if(z<=3){
						zz=1;
					}
					else{
						zz=2;
					}
						
					}
					
			
			}
			for(int i=1;i<=5;i++){
				if(s[2]==ss[i]){
				
					c=i;
					if(c<=3){
						cc=1;
					}
					else{
						cc=2;
					}
						
				}
			}
			if(zz==cc){
				cout<<1;
				if(max(z,c)-min(z,c)==1){
					cout<<1;
				}
					
				
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
	}
	return 0;
}
