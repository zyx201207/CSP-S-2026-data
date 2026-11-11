#include<bits/stdc++.h>
using namespace std;
int xx[10005][10005],c[10005];

void zh(int x,int y){
	int i=0;
	while(x){
		xx[i][y]=x%2;
		i++;
		x/=2;
	}
	c[y]=i;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=-2e9;
	long long sum=0;int ai[10005],aj=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		maxn=max(x,maxn);
		zh(x,i);
		
		if(i==0){
			for(int j=0;j<c[0];j++){
				ai[j]=xx[j][i];
			}
			aj=c[0];
		}
		if(i>=1){
			for(int j=min(c[i],aj)-1;j>=0;j--){
				if(ai[j]==xx[j][i]){
					ai[j]=1;
				}else{
					ai[j]=1;
				}
				aj=min(c[i],aj);
			}
			
		}
	}
	if(m==1){
		cout<<maxn<<endl;
		return 0;
	}
	if(m==n){
		for(int j=aj-1;j>=0;j--){
			sum=sum*2+ai[j];
		}
		cout<<sum;
		return 0;
	}
	
	for(int i=min(c[0],c[1])-1;i>=0;i--){
		if(xx[i][0]==xx[i][1]){
			sum=sum*2+1;
		}else{
			sum=sum*2+0;
		}
	}
	cout<<sum;
	return 0;
}