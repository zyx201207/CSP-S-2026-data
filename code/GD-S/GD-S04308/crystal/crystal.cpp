#include <bits/stdc++.h>
#define N 600005
using namespace std;
int i,j,k,x,y,n;
long long m;
long long a[N];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	scanf("%lld",&m);
	long long mm=m;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	int num2=-1,num3=1,num4=n+1,num5=-1;
	for(i=1;i<n;i++){
		if(a[i]==a[i+1]){
			num3++;
			num4=min(num4,i);
		}else{
			if(num2<num3){
				num5=num4;
			}
			num4=n+1;
			num2=max(num2,num3);
			num3=1;
		}
		if(i==n-1 && a[i]==a[i+1]){
			if(num2<num3){
				num5=num4;
			}
			num2=max(num2,num3);
			num3=0;
		}
	}
	if(num4==n+1){
		num5=n+10;
		num2=0;
		num3=0;
	}
	int num=1;
	for(i=1;i<n;i++){
		m-=i*(a[i+1]-a[i]);
		if(m<0){
			if(num==1){
				num=0;
			}
			break;
		}
		num++;
	}
	int num6=num2,num7=num2;
	m=mm;
	for(i=num5+num2-1;i<n;i++){
		m-=i*(a[i+1]-a[i]);
		if(m<0){
			break;
		} 
		num6++;
	}
	m=mm;
	if(num4==n+1){
		num5=0;
		num2=0;
		num3=0;
	}
	for(i=num5;i>1;i--){
		m-=a[num5]-a[i-1];
		
		if(m<0){
			break;
		}
		num7++;
	}
	printf("%d",max(max(num6,num),num7));
	return 0;
}
