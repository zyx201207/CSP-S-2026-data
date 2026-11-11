#include<bits/stdc++.h>
using namespace std;
int n,m,num;
long long a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int h=0,j=1,g=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=0,y=1,z=0;
		while(a[i]!=0){
			x+=a[i]%2*y;
			y*=10;
			a[i]/=2;
			z++;
		}
		a[i]=x;
	}
	int num=0,e=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int x=a[i],y=a[j];
			int t=0,r=1,p=0;
			while(x!=0&&y!=0){
				if(x%10==y%10) t+=x%10*r;
				r*=10;
				x/=10;
				y/=10;
				p++;
			}
			if(t>num){
				num=t;
				e=p;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=e;i++){
		int y=num%10;
		if(y==1){
			int q=1;
			for(int j=1;j<=i-1;j++){
				q*=2;
			}
			sum+=q;
		}
		num/=10;
	}
	cout<<sum;
	return 0;	
}
