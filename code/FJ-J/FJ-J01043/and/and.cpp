#include<bits/stdc++.h>
using namespace std;
bool s[200010][40],ans[40];
int num[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt=0,sum=0,f=0,f2=0,w;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a,b=0;
		cin>>a;
		while(a){
			b++;
			if(a%2==1) s[i][b]=1;
			a/=2;
			
		}
		cnt=max(b,cnt);
	}
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=n;j++) num[i]+=s[j][i];
		ans[i]=1;
	}
	for(int i=cnt;i>=0;i--){
		if(num[i]>=m){
			if(!f){
				w=i;
				f++;
			}
			for(int j=1;j<=n;j++){
				if(s[j][i]==0){
					for(int k=1;k<=cnt;k++) s[j][k]==1?num[k]--,s[j][k]=0:s[j][k]=0;
				}
			}
			
		}
		
	}
	for(int j=1;j<=w;j++){
		for(int k=1;k<=n;k++){
			if(s[w][j]) ans[j]=min(ans[j],s[k][j]);
		}
	}
	for(int i=w+1;i<=cnt;i++){
		ans[i]=0;
	}
	for(int i=1;i<=cnt;i++) sum=sum*2+ans[i];
	cout<<sum<<endl;
	return 0;
}
