#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[200001][33];
int b[33];
int d[200001];
unsigned long long int ans=0;
void change(unsigned long long int x,int y){
	int i=0;
	while(x){
		c[y][i]=x%2;
		b[i]+=x%2;
		x/=2;
		i++;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		unsigned long long int a;
		scanf("%lld",&a);
		change(a,i);
	}
	int l=33;
	bool flag=0,last=0,f=1;
	while(f){
		l--;
		if(b[l]>=m){
			for(int i=1;i<=n;i++){
				if(c[i][l]==0){
					d[i]=1;
				}
			}
			ans+=int(pow(2,l));
			last=1;
			l--;
			f=0;
		}
	}
	for(int i=l;i>=0;i--){
		unsigned long long int h=0;
		flag=0;
		int j=0;
		while(j<=n){
			j++;
			if((c[j][i+1]==0&&last==1)||d[j]==1){
				d[j]=1;
	    		continue;
			}
			if(c[j][i]==1){
				h++;
			}
			if(h>=m){
				flag=1;
			}
		}
		if(flag==1){
			ans+=int(pow(2,i));
		}
		last=flag;	
	}
	printf("%lld",ans);
	return 0;
} 
