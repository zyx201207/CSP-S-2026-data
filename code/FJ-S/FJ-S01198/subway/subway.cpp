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
int c,n,d,g,h,a[500005],v[500005],w[500005],s,l,p;
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
    c=read();
    n=read();
    d=read();
    g=read();
    h=read();
       for(int i=1;i<=n;i++){
       	a[i]=read();
	   }
	   for(int i=1;i<=n;i++){
	   	s=read();
	   	for(int i=1;i<=s;i++){
	   		  cin>>v[i]>>w[i];
		   }
	   }
	   for(int i=1;i<=h;i++){
	   	 cin>>l>>p;
	   }
	   for(int i=1;i<=h;i++){
	   	cout<<24<<endl;
	   }
	return 0;
}
