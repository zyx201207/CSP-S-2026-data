#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n+10];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=-1; 
		for(int i=0;i<n;i++){
			if(ans<=a[i])ans=a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		int m1=0,m2=0,ans2=0,ans1=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int x=a[i],y=a[j];
				while(x>0){
					m1=m1*10+x%2;
					x/=2;
				}
				while(y>0){
					m2=m2*10+y%2;
					y/=2;
				}
				int l[100000],k=0;
				while(m1>0||m2>0){
					if((m1%10)==1&&(m2%10)==1)l[k]=1;
					else l[k]=0;
					k++;
					m1/=10;
					m2/=10;
				}
				int u=1;
				for(int p=k-3,o=0;p>=0;p--,o++){
					if(o==0)u=1;
					else{
						for(int h=1;h<=o;h++){
							u*=2;
						}
					}
					ans2+=l[p]*u;
				}
				if(ans2>=ans1)ans1=ans2;
				m1=0;
				m2=0;
			}
		}
		cout<<ans1;
	}
	return 0;
}
