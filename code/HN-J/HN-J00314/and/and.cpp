#include<bits/stdc++.h>
using namespace std;
int m,n,ans,ans1;
struct rn{
	int a,ws;
	bool o[40];
}r[200005];
int jz(int x,int y){
	bool b[40];
	int flag;
	while(x){
		flag++;
		b[flag]=x%2;
		x/=2;
	}
	r[y].ws=flag;
	for(int i=flag;i>=1;i--)
		r[y].o[i]=b[i];
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>r[i].a;
		jz(r[i].a,i);
	}	
	if(n==m){
		for(int i=1;i<n;i++){
			for(int j=1;j<=max(r[i].ws,r[i+1].ws);j++){
				if(r[i].o[j]==r[i+1].o[j]) r[i+1].o[j]=1;
				else r[i+1].o[j]=0;
//				cout<<r[i+1].o[j]<<endl;
			}
//			cout<<endl;
		}	 	
		for(int i=1;i<=r[n].ws;i++) ans+=int(pow(2,i-1))*r[n].o[i];
	}
	else if(m==1)
		for(int i=1;i<=n;i++) 
			ans=max(ans,r[i].a);
	else if(m==2)
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;i++)
				for(int k=1;k<=max(r[i].ws,r[i+1].ws);k++){
					if(r[i].o[j]==r[j].o[j]) ans1+=int(pow(2,i-1))*1;
					ans=max(ans,ans1);
				}	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
