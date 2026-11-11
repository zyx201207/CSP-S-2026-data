#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	int a[n+5]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int a2[n+5]={0};
	int t[n+5]={0};
	int sum=0;
	for(int i=1;i<=n;i++){
		sum=0;
		while(a[i]>0){
			sum=sum*10+a[i]%2;
			t[i]++;
		}
		a2[i]=sum;
	}
	int a3[n+5]={0};
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(t[i]<t[j]){
				for(int z=t[i];z<=t[j];z++)	a2[i]*=10;
			}else if(t[i]>t[j]){
				for(int z=t[j];z<=t[i];z++)	a2[j]*=10;
			}
			int p=a2[i],p2=a2[j],num=0;; 
			while(p>0){
				if((p%10)==(p2%10)){
					num=num*10+1;
				}else{
					num=num*10;
				}
			}
			a3[i]=num;
		}
	}
	int q3=0;
	for(int i=1;i<=n;i++){
		int q2=0,r=10;
		while(a3[i]>0){
			int q=a3[i]%r;
			r*10;
			q2+=q;
			q=a3[i]%r;
			for(int j=2;j<=w;j++){
				q*=2;
			}
			q=a3[i]%r;
			r*=10;
		}
		if(q2>q3) q3=q2;
	}
	cout<<q3;
	return 0;
}
