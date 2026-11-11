#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,max,ans,hl;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long nm[n+5],a[n+5],b[2][35]={0};
	b[0][1]=1;
	for(int i=2;i<=30;i++){
		b[0][i]=b[0][i-1]*2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if(a[i]>=b[0][j] && a[i]<b[0][j+1]){
				b[1][j]++;
			}
		}
	}
	for(int i=30;i>=0;i--){
		if(b[1][i]>=3){
			c=i;
			break;
		}
	}
	q=0;
	if(c!=0){
		for(int i=1;i<=n;i++){
			if(a[i]>=b[0][c] && a[i]<b[0][c+1]){
				q++;
				nm[q]=a[i];
			}
		}
		for(int i=1;i<=m;i++){
			int max,hl=0;
			max=0;
			for(int j=1;j<n;j++){
				if(nm[j]>max){
					hl=max;
					max=nm[j];
					nm[j]=hl;
				}
			}
			if(i==1){
			ans=max;
			}
			else{
				ans=ans&max;
			}
		}
		cout<<ans;
	}
	else{
		for(int t=1;t<m;t++){
			int q1,q2,max=0;
			q1=q2=max=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]&a[i]>max){
						max=a[j]&a[i];
						q1=j;
						q2=i;
					}
				}
			}
			if(t==1){
				ans=max;
			}
			else{
				ans=ans&max;
			}
			a[q1]=ans;
			a[q2]=0;
		}
		cout<<ans;
	}
	return 0;
}
