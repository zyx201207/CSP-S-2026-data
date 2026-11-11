#include<bits/stdc++.h> 
using namespace std;
int a[200005];
char b[200005];
long long sum; 
int n;
int o;
int main(){
freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
}
 if(sum%2==1){
		int y=sum;
		sum=sum/2+1;
		for(int i=1;i<=n;i++){
			if(sum<=a[i]){
				o=i;
				break;
			}
			sum-=a[i];
	}sum=y;
	int flag=0;
	int x=0;
	int op=0;
	for(int i=1;i<=n;i++){
		
		if(i==o){
			int p=sum-x;
			if(p<x)flag=0,op=x-p;
			else flag=1,op=p-x;
			break;
		}x+=a[i];
	}int i,j;long long ans=0;
	a[o]=op;
	if(flag==0){
		
	 i=o-1,j=o;}
	 else i=o,j=o+1;
		while(i>=1&&j<=n){
			if(a[i]==0)i--;
			if(a[j]==0)j++;
			if(b[i]!=b[j]){
				if(a[i]>a[j])ans+=a[j],a[i]-=a[j],a[j]=0;
				if(a[i]<=a[j])ans+=a[i],a[i]=0,a[j]-=a[i];
			}
			else {
					if(a[i]>a[j])a[i]-=a[j],a[j]=0;
				if(a[i]<=a[j])a[i]=0,a[j]-=a[i];
			}
		}cout<<ans;
		
}
 if(sum%2==0){
		int y=sum;
		sum=sum/2;
		for(int i=1;i<=n;i++){
			if(sum<=a[i]){
				o=i;
				break;
			}
			sum-=a[i];
	}sum=y;
	int flag=0;
	int x=0;
	int op=0;
	for(int i=1;i<=n;i++){
		
		if(i==o){
			int p=sum-x-a[i];
			if(p<x)flag=0,op=x-p;
			else flag=1,op=p-x;
			break;
		}x+=a[i];
	}int i,j;long long ans=0;
	a[o]=op;
	if(flag==0){
		
	 i=o-1,j=o;}
	 else i=o,j=o+1;
		while(i>=1&&j<=n){
			if(a[i]==0)i--;
			if(a[j]==0)j++;
			if(b[i]!=b[j]){
				if(a[i]>a[j])ans+=a[j],a[i]-=a[j],a[j]=0;
				if(a[i]<=a[j])ans+=a[i],a[i]=0,a[j]-=a[i];
			}
			else {
					if(a[i]>a[j])a[i]-=a[j],a[j]=0;
				if(a[i]<=a[j])a[i]=0,a[j]-=a[i];
			}
		}cout<<ans;
	}
	return 0;
}



