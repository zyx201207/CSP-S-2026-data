#include<bits/stdc++.h>
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
int n,a[500005],b[500005],d[500005];
long long m;
long long v;
	int j,k=1,p=1,s=1;
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	v=m;
	for(int i=1;i<=n;i++){
		a[i]=read();		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
		for(int i=1;i<n;i++){
			j=i;
		  while(v>=b[j]*(j+1-i) and j<n){
		  		v-=b[j]*(j+1-i);
		  		j++;
		  		k++; 
		  }		  
		  s=max(s,k);
		  v=m;
		  k=1;
		  p++;
	}
write(s);
	return 0;
}
