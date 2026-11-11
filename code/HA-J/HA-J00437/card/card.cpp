#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,m,t=1;
int pd[N],d[N],a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		if(n-i+1==m){
			for(int j=i;j<=n;j++){
				pd[a[j]]++;
				
			}
			
			for(int j=1;j<=m;j++){
				if(pd[j]==0){
					t=0;
				}
			}
			if(t==1){
				for(int j=1;j<=m;j++){
					d[j]+=1;
				}
				t=0;
			}	
			else{
				if(a[i]!=a[n])d[a[i]]+=1,d[a[n]]+=1;
				else d[a[i]]+=1;
			}
		}
		else{
			if(a[i]!=a[n])d[a[i]]+=1,d[a[n]]+=1;
			else d[a[i]]+=1;
		}

	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	cout<<endl;
	return 0;
} 






