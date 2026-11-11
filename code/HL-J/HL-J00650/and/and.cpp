#include<bits/stdc++.h>
using namespace std;
long long x[200005];
long long a[200005][35];
long long maxx[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int p=0,q=0;
	int maxlen=0;
	for(int i=1;i<=n;i++){
		q=0;
		++p;
		long long temp=x[i];
		while(temp!=0){
			a[p][++q]=temp%2;
			temp/=2;
		}
		if(q>maxlen){
			maxlen=q;
		}
	}
	int sum=0;
	int ans=0;
	int j=1;
	bool e=0;
	for(int i=maxlen;i>=1;i--){
		sum=0;
		for(j=1;j<=p;j++){
			if(a[i][j]==1){
				sum++;
			}
		}
		if(sum>=k){
			ans=j;
			e=1;
			break;
		}
		if(e) break;
	}
	long long l=0;
	for(int i=1;i<=n;i++){
		if(a[i][ans]==1){
			maxx[++l]=x[i];
		}
	}
	sort(maxx+1,maxx+l+1);
	int xx=0,yy=0;
	for(int i=l;i>=l-k;i--){
		yy=0;
		++xx;
		long long temp=maxx[i];
		while(temp!=0){
			a[xx][++yy]=temp%2;
			temp/=2;
		}
	}
	int ans2=0;
	for(int i=1;i<=30;i++)a[xx+1][i]=1;
	for(int i=1;i<=xx;i++){
		for(int j=1;j<=yy;j++){
			if(a[i][j]==0){
				a[xx+1][j]=0;
			}
		}
	}
	for(int i=1;i<=ans;i++){
		ans2+=a[xx+1][i]*pow(2,i);	
	}
	cout<<ans2;
	return 0;
} 
