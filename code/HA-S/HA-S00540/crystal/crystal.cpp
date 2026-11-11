#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],max1=0,try1=0,tim=0;
void thoughout(long long m,long long c){
	for(long long i = n;i>0;i--){
		if(a[i]<=a[c]&&m>=a[c]-a[i]){
			m-=a[c]-a[i];
			try1++;
		}
	}
}
void count1(long long m,long long c){
	long long t=0,v=0;
	if(c>n){
		tim=c-1;
		return ;
	}else if(m==0){
		tim=c-1;
		return ;
	}
	for(long long i = 0;i<c;i++){
		if(a[i]<a[c]&&m>=a[c]-a[i]){
			t+=a[c]-a[i];
		}
	}
	if(m>=t){
		for(long long i = 0;i<c;i++){
			a[i]=a[c];
		}
		m-=t;
	}else{
		for(long long i = 0;i<n;i++){
			if(a[i]==a[c]){
				v++;
			}
		}
		thoughout(m,c);
		if(try1>=v){
			max1=try1;
		}else{
			max1=v;
		}
		return ;
	}
	count1(m,c+1);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(long long i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	count1(m,1);
	if(max1!=0){
		cout<<max1;
	}else{
		for(long long i =0;i<n;i++){
			if(a[i]==a[tim]){
				max1++;
			}
		}
		cout<<max1;
	}
}

