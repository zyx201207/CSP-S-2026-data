#include<bits/stdc++.h>
using namespace std;
int a[500005];//dianshu
bool vis[500005];//1 zhuoshang
int cnt[500005];//cishu
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxx=0;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			f=1;
		}else if(a[i]<a[i+1]){
			f=2;
		}
	}
	if(f==1){
		cout<<n;
	}else if(f==2){
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
	}else if(f==0){
	for(int i=1;i<=n;i++){
		vis[i]=1;
		for(int j=i+1;j<=n;j++){
			vis[j]=1;
			for(int d=i;d<j;d++){
			//cout<<a[d]<<" "<<a[j]<<"  "<<endl;
				if(a[d]==a[j]&&vis[d]==1){
				for(int k=d;k<j;k++){
					vis[k]=0;
				}	
			}		
		}
		for(int j=1;j<=n;j++){
			if(vis[j]==1){
				cnt[a[j]]++;
			}
		}
		for(int j=1;j<=n;j++){
			cout<<vis[j]<<"  ";
		}cout<<endl;
		for(int j=1;j<=maxx;j++){
			vis[j]=0;
		}
	}
}
	for(int i=1;i<=n;i++){
		if(cnt[i]!=0)
		cout<<cnt[i]<<" ";
	}

	}
//	/*
//	3 1 2 1 3 2 3 1 2 1
//	3 1 
//	*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
