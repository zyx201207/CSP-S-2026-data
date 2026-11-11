#include <bits/stdc++.h>
using namespace std;
struct c{
		long long a;
		char b;
	};
	c t[200005];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	long long sum=0,sum1=0;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		sum+=a;
		t[i].a=a;
		t[i].b=b;
	}
	sum/=2;
	long long aa=0,bb=n-1,aaa=t[0].a,bbb=t[n-1].a,f;
	while(sum&&aa<bb){
		if(aaa<=bbb){
			f=aaa;
		}else{
			f=bbb;
		}
		if(!(t[aa].b==t[bb].b)){
			sum1+=f;
		}
		aaa-=f;
		bbb-=f;
		if(aaa==0){
			aa+=1;
			aaa=t[aa].a;
		}
		if(bbb==0){
			bb-=1;
			bbb=t[bb].a;
		}
		sum-=f;
	}
	cout<<sum1;
}

//	for(int i=0;i<=0;i++){
//		
//	}
