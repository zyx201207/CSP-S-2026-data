#include<bits\stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
		while(ch>='0' && ch<='9'){
	    x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	} 
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int c,t,n,m,a[2000005];
int main(){
		freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
     c=read();
     t=read();
     while(t--){
       n=read();
       m=read();
       for(int i=1;i<=n;i++){
       	a[i]=read();
	   }
	   sort(a+1,a+n+1);
	   	if(m>=a[n]-a[1]){
		 		cout<<0<<endl;
			 }
	   else  if(n>5000 && n<=2000000){
	     	  if(m<2*(a[2]-a[1])){
	     	   	    cout<<0<<endl;
				}
				else{
					int k=m/(a[2]-a[1]);
			  write((k-1)*(n-k-1)-(k-2));
			  cout<<endl;
				}
		 }
	
	 }
	return 0;
}
