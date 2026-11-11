#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;

struct node{
	int id,num;
}f[N];

int n,m;
int a[N],b[N];
int ans=0;
int i,j;
int gh[201];

void ce(){
	i=j-1;
	
	int sum=m-b[j]*f[i].num;//剩余 
	int tot=f[j].num+f[i].num;//已选个数 
	j++;//当前查看是否加上 
	while(j<=n){
		if(sum>=b[j]*tot){
			sum-=b[j]*tot;
			tot+=f[j].num;
			j++;
			continue;
		}
		int o=(f[j-1].id-f[i].id)*f[i].num;
		if(o>=b[j]*tot && f[i].num<f[j].num){
			sum+=o-b[j]*tot;
			i++;
			j++;
		}
		
		else{
			break;
		}
	}
	int u=0;
	for (int l=i;l<=j;l++){
		u+=f[l].num;
	}
	ans=max(ans,u-1);
	return ; 
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for (int k=1;k<=n;k++){
		cin>>a[k];
	}
	sort(a+1,a+n+1);
	
	int M=1;
	for (int i=1;i<=n;i++){
		f[M].id=a[i];
		f[M].num=1;
		while(a[i+1]==f[M].id){
			f[M].num++;
			i++;
		}
		b[M]=f[M].id-f[M-1].id;
		M++;
	}
	n=M-1;
	
	j=2;
	for (int l=1;l<=n;l++){
		cout<<f[l].id<<" "<<f[l].num<<"\n";
	}
	while(j<=n){
		if(b[j]*f[i].num<=m){
			ce();
		}
		j++;
	}
	cout<<ans;
	
	return 0;
}
