#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
		while(ch>='0'&& ch<='9'){
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
int n,m;
int k=1,j;
int a[500005],b[500005],s[500005];
int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
	a[i]=read();
		   b[a[i]]++;
	}
	
	   for(int p=1;p<=n;p++){	 
	       b[a[p-1]]--;  
		for(int i=p;i<=n;i++){	
		k=1;		
			j=i;
        if(b[a[i]]!=1){
        	while(k<b[a[i]]){
        	   j++;
				if(a[j]==a[i]) {
					k++;
				}
			}
		}
	 
		s[a[i]]++;
		i=j;
	}
}
  for(int i=1;i<=m;i++){
  	write(s[i]);
  	putchar(' ');
  }
	return 0;
} 
