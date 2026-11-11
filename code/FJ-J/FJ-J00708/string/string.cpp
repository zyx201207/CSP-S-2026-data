#include<bits/stdc++.h>
using namespace std;
char y[200010];
int c[20]; 
int zs[20],a[200010];
int n,l=0,l2=0,ans=0,k;
void gjd(int js){
	l=0;
	while(js>0){
		c[l]=js%10;
       l++;
       js/=10;
	}
		l2=max(l2,l);
		for(int j=1;j<=l;j++){
			zs[j]+=c[l-j];
			
			if(zs[j]>9){
				zs[j]-=10;
				zs[j+1]++;
				if(j==l==l2){
					l2++;
				}
			}
		}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	k=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>y[i];
    int lf=1,ri=k;
	while(k){
		if(k==1)break;
		if(y[lf]==y[ri]){
			if(a[lf]>a[ri]){
			a[lf]-=a[ri];
			ri--;	
			}else{
				a[ri]-=a[lf];
				lf++;
				if(a[lf]==a[ri])ri--;
			}
		}else{
			if(a[lf]>a[ri]){
			a[lf]-=a[ri];
			gjd(a[ri]);
			ri--;	
			}else{
				a[ri]-=a[lf];
				gjd(a[lf]);
				lf++;
				if(a[lf]==a[ri])ri--;
			}
		}
		k--;
	}
	if(l2==0)cout<<0;
	for(int i=1;i<=l2;i++){
		cout<<zs[i];
	}
} 
