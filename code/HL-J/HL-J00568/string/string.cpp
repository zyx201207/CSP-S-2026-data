#include <bits/stdc++.h>
using namespace std;
char st[100010];
long long dlen[100010];
long long n,num1=0,l=0,sd=0,ld=1,rd=1;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		sd+=a;
		dlen[i]=sd;
		char d;
		cin>>d;
		st[i]=d;
		l+=a;
	}
	
	
	rd=n; 
	
	
	long long lx=l/2;
	
	
	
	for(int i=1;i<=lx;i++){
		long long l1,r1;
		l1=i;
		r1=l+1-i;
		

		
		char p,q;
		for(int j=ld;j<=n;j++){
			if(l1<=dlen[j]){
				ld=j;
				

				
				p=st[j];

				l1++;
				break;
			}
		}
		for(int k=rd;k>=1;k--){
			if(r1>dlen[k-1]){
				rd=k;
				

				
				q=st[k];

				r1--;
				break;
			}
		}
		

		
		if(p!=q) num1++;
	}
	cout<<num1;
	return 0;
}
