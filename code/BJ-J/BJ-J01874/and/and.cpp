#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005][32],maxw=-888,b[32],book[200005],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x,w=1;
		long long l=1;
		//cout<<i<<"  ";
		scanf("%d",&x);
		//if(i==619)cout<<x;
		//cout<<i<<"  ";
		while(666){
			//cout<<l<<" "<<x<<"  ";
			l*=2;
			if(l>x)break;
			w++;
		}
		//cout<<i<<"  ";
		l/=2;
		//cout<<i<<" "<<w<<" "<<l<<endl;
		//if(i==618)cout<<x<<"   ";
		while(666){
			//cout<<i<<" ";
			if(x<=0)break;
			if(x>=l){
				//cout<<x<<" "<<l<<"  ";
				a[i][w]=1;
				b[w]++;
				if(w>maxw)maxw=w;
				x-=l;			
				if(x<=0)break;
				//cout<<x<<" ";
			}

			l/=2;
			w--;
		}
	}
	//cout<<7788;
	//cout<<maxw<<b[1]<<a[1][1];
	int l=1;
	for(int i=1;i<maxw;i++)l*=2;
	for(int i=maxw;i>=1;i--){
		if(b[i]<m){
			l/=2;
			continue;
		}
		for(int j=1;j<=n;j++){
			if(book[j]==1)continue;
			if(a[j][i]==0){
				book[j]=1;
				for(int k=1;k<=31;k++)
					if(a[j][k]==1)b[k]--;
			}
		}
		ans+=l;
		l/=2;
	}
	cout<<ans;
	return 0;
}
