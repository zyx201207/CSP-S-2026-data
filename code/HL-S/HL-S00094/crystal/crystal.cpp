#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
int d[N];
int a[N];
int c[N];//dijihaoyuansu chuxiancishu
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	int mind=0x3f3f3f3f;
	d[1]=a[1];	
	int pmin=-1;
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if(d[i]<mind){
			mind=d[i];
			pmin=i;
		}
	}
	if(pmin==-1){
		cout<<n;
	}
	memset(c,0,sizeof(c));
	int l=a[1];
	int s=1;
	c[1]=1;
	int maxd=0;
	int maxp=-1;
	for(int i=2;i<=n;i++){
		if(l==a[i]){
			c[s]++;
		}
		else{
			l=a[i];
			s=i;
			c[i]=1;
		}
		if(maxd<c[s]){
			maxd=c[s];
			maxp=s;
		}
	}
	int maxpp=maxp;
	for(int i=maxp+1;i<=n;i++){
		if(c[i]==0){
			maxpp=i;
			
		}
	}
	
	int minnn=0x3f3f3f3f;
	int flag=0;
	if(maxp>1){
		minnn=d[maxp];
		flag=1;
	}
	
	if(maxd>n-maxd){// youxian kaolv quxiang zuiduo erbushi chazhi zuixiao
		ans=maxd;
		if(maxpp+1<=n&&minnn>d[maxpp+1]){
			minnn=d[maxpp+1];
			flag=2;
		}
			
		while(m>=minnn&&flag!=0){
			m-=minnn;
			ans++;
			if(flag==1){
				maxp-=1;
				if(maxp-1>1){
					maxp-=1;
					minnn=a[s]-a[maxp];
					flag=1;
					if(maxpp+1<=n){
						minnn=min(minnn,a[maxpp+1]-a[s]);
						if(minnn==a[maxpp+1]-a[s]){
							flag=2;
							maxp+=1;
						}
					}
				}
				else if(maxpp+1<=n){
					minnn=a[maxpp+1]-a[s];
					flag=2;
				}
				else flag=0;
			}
			else {
				maxpp+=1;
				if(maxp-1>1){
					maxp-=1;
					minnn=a[s]-a[maxp];
					flag=1;
					if(maxpp+1<=n){
						minnn=min(minnn,a[maxpp+1]-a[s]);
						if(minnn==a[maxpp+1]-a[s]){
							flag=2;
							maxp+=1;
						}
					}
				}
				else if(maxpp+1<=n){
					minnn=a[maxpp+1]-a[s];
					flag=2;
				}
				else flag=0;
			}
		}
	}
	
	else{
		bool flag=1;
		int k=d[2];
		for(int i=2;i<=n;i++){
			if(d[i]!=k)flag=0;
		}
		if(flag){
			int j=k;
			while(m>=j){
				m-=j;
				ans++;
				j+=k;
			}
		}
		
	}
	cout<<ans;
	return 0;
}