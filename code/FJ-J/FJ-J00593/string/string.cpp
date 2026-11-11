#include<bits/stdc++.h>
using namespace std;
long long b[200005]; 
char a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	int n;
	cin>>n;
	long long all=0,l=0;
	for(int i=0;i<n;i++){
		cin>>b[i]>>a[i];
	}
	for(long long i=0;i<n;i++){
		l+=b[i];
	}
	long long x=0,y=n-1;
	while(x<y){
		if(a[x]==a[y]){
			if(b[x]<b[y]){
				b[x]=0;
				b[y]=b[y]-b[x];
				x++;
			}else if(b[x]>b[y]){
				b[y]=0;
				b[x]=b[x]-b[y];
				y--;
			}else{
				
				b[x]=0;
				b[y]=0;
				x++;
				y--;
			}
		}else{
			if(b[x]<b[y]){
				all+=b[x];
				b[y]=b[y]-b[x];
				b[x]=0;
				x++;
			}else if(b[x]>b[y]){
				all+=b[y];
				b[x]=b[x]-b[y];
				b[y]=0;
				y--;
			}else{
				all+=b[y];
				b[x]=0;
				b[y]=0;
				x++;
				y--;
			}
		}
	}
	cout<<all;
	return 0;
		
}
