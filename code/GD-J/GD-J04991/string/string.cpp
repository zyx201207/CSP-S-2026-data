#include<bits/stdc++.h>
using namespace std;
struct aaa{
	long long l,r;
	char b;
}k[114154];
int main(){
	long long c=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[114514];
	cin>>n;
	if(n==1){
		cout<<"0";return 0;
	}
	else if(n==2)
	{
		char kkk,mmm;
		cin>>a[0]>>kkk>>a[1]>>mmm;
		if(kkk!=mmm){
		
			cout<<min(a[0],a[1]);}
		else cout<<"0";
		return 0;
	}
	
	else{
		long long x;
		char b[114514];
		long long s[114514]={0};
		for(int i=0;i<n;i++){
			cin>>a[i]>>k[i].b;
			s[i+1]=s[i]+a[i];
			k[i].l=s[i];
			k[i].r=s[i+1]-1;
		}
		x=n;
		for(int i=0;i<n;i++){
			if(k[i].l>=s[n]/2&&k[i].r>=s[n]/2){
				k[i].l=s[n]-1-k[i].l;
				k[i].r=s[n]-1-k[i].r;
			}
			if(k[i].l<s[n]/2&&k[i].r>=s[n]/2){
				k[x].r=k[i].r;
				k[i].r=s[n]/2-1;
				k[x].b=k[i].b;
				k[x].l=a[n]/2;
				x++;
			}
			
		}
		for(int i=0;i<x/2;i++){
			for(int j=x/2;j<=x;j++){
				if(k[j].l>=k[i].l&&k[j].l<=k[i].r&&k[j].r>=k[i].l&&k[j].r<=k[i].r){
					if(k[j].b==k[i].b){
						c+=k[j].r-k[j].l+1;
					}
				}
				else if((k[j].l>=k[i].l&&k[j].l<=k[i].r)&&(k[j].r>k[i].r)){
					if(k[j].b==k[i].b){
						c+=k[i].r-k[j].l+1;
					}
				}
				else if((k[j].l<k[i].l)&&(k[j].r>=k[i].l&&k[j].r<=k[i].r)){
					if(k[j].b==k[i].b){
						c+=k[j].r-k[i].l+1;
					}
				}
			}
		}
		cout<<s[n]/2-2*c;
		return 0; 
	}
}
