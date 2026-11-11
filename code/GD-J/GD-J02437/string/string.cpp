#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char ch[200005];
long long zong=0;
int f=1,f1=1;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		zong+=a[i];
		if(a[i]>500) f=0;
		if(a[i]>2) f1=0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if((n<=200005&&f1==1)||(n<=2000&&f==1)){
		string tttttt="";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];i++) tttttt+=ch[i];
		}
		for(int i=0;i<tttttt.size()/2+1;i++){
			if(tttttt[i]!=tttttt[n-i]) ans++;
		}
		cout<<ans;
		return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	long long len1=1,len2=n;
	long long i=a[1];
	long long x=a[len1],y=a[len2];
	char x1=ch[len1],y1=ch[len2];
	while(1==1){
		if(i>zong/2) break; 
		if(x==0) x=a[len1],x1=ch[len1];
		if(y==0) y=a[len2],y1=ch[len2];
		
		
		if(len1==len2){
			x=a[zong/2-i],x1=ch[len1];
			y=a[len2-zong/2],y1=ch[len2];
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		if(x==y){
			if(x1==y1){
				i+=x;
				len1++;
				len2--;
			}
			else{
				i+=x;
				len1++;
				len2--;
				ans+=x;
			}
			x=0,y=0;
		}
		if(x>y){
			if(x1==y1){
				x-=y;
				i+=y;
				len2--;
			}
			else{
				x-=y;
				i+=x;
				len2--;
				ans+=y;
			}
			y=0;
		}
		if(x<y){
			if(x1==y1){
				y-=x;
				i+=x;
				len1++;
			}
			else{
				y-=x;
				i+=x;
				len1++;
				ans+=x;
			}
			x=0;
		}
		
	}
	cout<<ans;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
} 
