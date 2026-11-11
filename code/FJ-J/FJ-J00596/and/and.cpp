#include <iostream>
using namespace std;
string a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	string b,c;
	int i=0,j=0,w,d,e,f,sum=0,g,h=0,k,l;
	cin>>d>>e;
	
	
	for(i;i<d;i++){
		cin>>f;
		b="";
		while (f>0){
			if(f%2==1){
				f-=1;
				b+="1";
			}
			else b+="0";
			f/=2;
		}
		a[i]=b;
		
	}
	for(i=0;i<d;i++){
		b=a[i];
		for(j=i+1;j<d;j++){
			c=a[j];
			g=1;
			h=0;
			for(w=0;w<min(b.length(),c.length());w++){
				
				if(b[w]==c[w]&&b[w]=='1')h+=1*g;
				g*=2;
			}
			if (h>sum){
			sum=h;
			k=i;
			l=j; 
			}
			
		}
	}
	h=sum;
	for(i=0;i<e-2;i++){
		sum=0;
		b="";
		while (h>0){
			if(h%2==1){
				h-=1;
				b+="1";
			}
			else b+="0";
			h/=2;
		}
		for(j=0;j<d;j++){
			if(j==l||j==k)continue;
			c=a[j];
			g=1;
			h=0;
			for(w=0;w<min(b.length(),c.length());w++){
				
				if(b[w]==c[w]&&b[w]=='1')h+=1*g;
				g*=2;
			}
			if (h>sum){
			sum=h; 
			}
		}
		h=sum;
		
	}
 	cout<<sum;
	return 0;
} 
