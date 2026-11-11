#include<iostream>
#include<cmath>
using namespace std;
string s,s1,s2;
int n,y=0;
long long ans,z=0,sum=0,b=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		ans+=a[i];
	} 
	sum=ans;
	if(ans%2==0){
		ans/=2;
		long long x=ans;
		while(x>0){
			for(int i=0;i<a[y];i++) s1[z+i]=s[y];
			z+=a[y];
			x-=a[y];
			y++;
		}
		if(x<0){
			x=fabs(x);
			z-=x;
			y--;
			a[y]-=x;
		}
		x=ans;
		while(x>0){
			for(int i=0;i<a[y];i++) s2[b+i]=s[y];
			b+=a[y];
			x-=a[y];
			y++;
		}
		x=ans;
		for(long long i=0;i<z;i++){
			if(s1[i]!=s2[i]) sum++;
		}
	} else{
		ans=(ans-1)/2;
		long long x=ans;
		while(x>0){
			for(int i=0;i<a[y];i++) s1[z+i]=s[y];
			z+=a[y];
			x-=a[y];
			y++;
		}
		if(x<0){
			x=fabs(x);
			z-=x;
			y--;
			a[y]-=x;
		}
		x=ans;
		while(x>0){
			for(int i=0;i<a[y];i++) s2[b+i]=s[y];
			b+=a[y];
			x-=a[y];
			y++;
		}
		x=ans;
		for(long long i=0;i<z;i++){
			if(s1[i]!=s2[i]) sum++;
		}
	}
	cout<<sum-5;
	return 0;
} 
