//уейкаж GZ-J00067 
#include<bits/stdc++.h>
using namespace std;
long long n;
long long N=0;
long long ans=0;
struct D{
	long long num=0;
	char inp='0';
}a[2000000];
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld %c",&a[i].num,&a[i].inp);
		N+=a[i].num;
	}
	
	if(N%2==1)N-=1;
	long long max=N/2;
	
	long long now=0;
	long long shang=1,xia=n;
	long long r1=0,r2=0;
	char cr1='0',cr2='0'; 
	r1=a[shang].num;
	cr1=a[shang].inp;
	r2=a[xia].num;
	cr2=a[xia].inp;
	while(now<=max){
		if(r1==0){
			shang++;
			r1=a[shang].num;
			cr1=a[shang].inp;
		}
		if(r2==0){
			xia--;
			r2=a[xia].num;
			cr2=a[xia].inp;
		}
		if(cr1==cr2){
			if(r1>=r2){
				r1-=r2;
				now+=r2;
				r2=0;
			}else{
				r2-=r1;
				now+=r1;
				r1=0;
			}
		}else{
			if(r1>=r2){
				if(r2+now<=max){
					ans+=r2;
					now+=r2;
					r1-=r2;
					r2=0;
				}else if(r2+now>max){
					ans+=max-now;
					now+=ans;
					break;
				}else{
					r1-=r2;
					now+=r2;
					r2=0;
				}
			}else{
				if(r1+now<=max){
					ans+=r1;
					now+=r1;
					r2-=r1;
					r1=0;
				}else if(r1+now>max){
					ans+=max-now;
					now+=max-now;
					break;
				}else{
					r2-=r1;
					now+=r1;
					r1=0;
				}
			}
			
		}
	}
	printf("\n%lld",ans);
	return 0;
		
}
