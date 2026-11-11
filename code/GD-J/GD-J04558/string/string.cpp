#include<bits/stdc++.h>
using namespace std;
int a[200000];
char c[200000];

int main(){
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	
	int n,li,ri,lc,rc,l,r;
	long long ai,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ai;
		a[i]=ai;
		cin>>c[i];
	}
	li=0,ri=n-1;
	l=a[0],r=a[ri];
	while(ri>li){
		lc=c[li],rc=c[ri];
			if(l>r){
				if(lc!=rc){
					ans+=r;}
				ri--;					
				l-=r;
				r=a[ri];	
			}
			else if(l==r){
				if(lc!=rc){
					ans+=l;}
				li++;
				ri--;
				l=a[li];
				r=a[ri];
			}
			else if(r>l){
				if(lc!=rc){
					ans+=l;}
				li++;
				r-=l;
				l=a[li];
			}
	}
	cout<<ans;
}
