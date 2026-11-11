#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,s,n,m,i,q;
	char C1[8],S1[8];
    char A=C1[1],B=C1[2],C=C1[3], D=C1[5],E=C1[6];
    char A=S1[1],B=S1[2],C=S1[3], D=S1[5],E=S1[6];
    
	cin>>c>>" ">>n>>C1[i]>>" ">>s>>" ">>m>>S1[q];
	
	if(18>=c<=1&&18>=s<=1){
		cout<<1<<" ";
		}else{cout<<0<<" ";}
		
	if(n-m==0||m-n==0){
		cout<<1<<" ";
		}else{cout<<0<<" ";}
		
	if(C1[i]-S1[q]<=1||S1[q]-C1[i]<=1){
		cout<<1<<" ";
		}else{cout<<0<<" ";}	
			
    if(C1[i]-S1[q]==0||S1[q]-C1[i]==0){
		cout<<1<<" ";
		}else{cout<<0<<" ";}

	return 0;
}
