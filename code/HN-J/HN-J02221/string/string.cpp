#include<iostream>
using namespace std; char a[10000000];
int main(){
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	int i,halfi,sum1=0,halfsum1,s=0,b,ao=1,j1,sb;
	
	char c;
	cin>>i;
	for(int i2=1;i2<=i;i2++){
		cin>>b>>c;sum1=sum1+b;
		for(int i3=1;i3<=b;i3++){
			a[ao]=c;ao=ao+1;
		
		}
	}halfsum1=sum1/2;sb=sum1%2;
	if(sb==1){
			j1=2;
		}
		else j1=1;
	for(int j=halfsum1;j>0;j--){
		
		  
			if(a[j]==a[j+j1]){
			s=s;
			}else {
			s=s+1;
			}
			j1=j1+2;
		
	}
	cout<<s;
	
	
	return 0;
}
