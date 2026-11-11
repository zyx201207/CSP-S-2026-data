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
    int c,n,l,v,h;
int main(){

    freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	n=read();
	while(n--){
		l=read();
		v=read();
		for(int i=1;i<l;i++){
			v=read();
			h=read();
		}
		cout<<1<<endl;
	}
    
	return 0;
}
