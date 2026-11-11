#include<iostream>
using namespace std;
int n,m,k=0,sum=0;
bool ans[40],s[200010],s1[200010];
bool ls[200010][40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		s[i]=1;
		int u,j=0;cin>>u;
		while(u>0){ls[i][j++]=u%2;u/=2;}
		k=max(k,j);
	}
	for(int j=k-1;j>=0;j--){
		int sze=0;
		for(int i=0;i<n;i++){
			if(s[i] && ls[i][j]==1){s1[i]=1;sze++;}
			else s1[i]=0;
		}
		if(sze<m) ans[j]=0;
		else{
			ans[j]=1;
			for(int i=0;i<n;i++) s[i]=s1[i];
		}
	}
	for(int j=k-1;j>=0;j--) sum=sum*2+ans[j];
	cout<<sum;
}
