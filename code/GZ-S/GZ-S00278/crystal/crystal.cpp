//GZ-S00278 ∂≠≤©”Ó 
#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,sum,cnt;
long long a[500010],b[500010];
bool f=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>100||a[i]<-100)f=1;
	}
	//5  101 102 103 104 105
	//3
	if(f){
		long long k=a[2]-a[1];//1
		while(m>0){
			m-=k*ans;
			if(m<=0)break;
			ans++;
		}
		cout<<ans;//<<' '<<m;
	}
	
	else {
	sort(a+1,a+n+1);
	//5 5 
	//5 8 -3 -1 2 2 7
	for(int i=1;i<=100;i++){
//int i=4;
		long long id=1,k=m,now=0;
		for(int j=1;j<=n;j++){
			if(i-a[j]<0)break;
			b[id]=i-a[j];
		//	cout<<b[id]<<' ';			
			id++;
		}
		sort(b+1,b+id);
		for(int i=1;i<id;i++){
			//cout<<b[i];
			k-=b[i];
			if(k<0)break;
			now++;
		}
		ans=max(ans,now);
	}
	cout<<ans;
}
	//◊Ó 
	return 0;
}
