#include<bits/stdc++.h>
using namespace std;
long long n,ans,len,l,r,arr[200005],s,lc,rc,c;
char a,b,ar[200050];
int main(){
	//freopen("string3.in","r",stdin);
	//freopen("string5.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		len+=x;
		char y;
		cin>>y;
		arr[i]=x; 
		ar[i]=y;
	}
	l=arr[1];
	r=arr[n];
	a=ar[1];
	b=ar[n];
	if(len%2==0){
		s=len/2+1;
		while(len>0){
			len-=(min(l,r)*2);
			//cout<<len;
			if(a!=b){
				ans+=min(l,r);
				c++;
			}
			if(l>r){
				rc++;
				l=l-r;
				r=arr[n-rc];
				b=ar[n-rc];
			}
			else if(r>l){
				lc++;
				r=r-l;
				l=arr[lc+1];
				a=ar[lc+1];
			}
			else {
				rc++;
				lc++;
				l=arr[lc+1];
				a=ar[lc+1];
				r=arr[n-rc];
				b=ar[n-rc];
			}	
		}
	} 
	else{
		s=n/2+2;
		while(len>1){
			len-=(min(l,r)*2);
			if(a!=b){
				ans+=min(l,r);
				c++;
				
			}
			if(l>r){
				rc++;
				l=l-r;
				r=arr[n-rc];
				b=ar[n-rc];
			}
			else if(r>l){
				lc++;
				r=r-l;
				l=arr[lc+1];
				a=ar[lc+1];
			}
			else {
				rc++;
				lc++;
				l=arr[lc+1];
				a=ar[lc+1];
				r=arr[n-rc];
				b=ar[n-rc];
			}	
		}
	}
	cout<<ans;
	return 0; 
}
