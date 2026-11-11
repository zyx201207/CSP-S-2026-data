#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010],b[2000010][2],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>a[i];
		
		for (int ss=1;ss<=n-3;ss++){
			for (int i=ss+1;i<=n;i++){
				b[i][0]=99999999;
				b[i][1]=0;
			}
			b[ss][0]=0;
			b[ss][1]=1;
			for (int i=ss+1;i<=n;i++){
				int wzz=i;
				while (wzz>=ss&&a[i]-a[wzz]<=d){
					if (b[wzz][0]+1<b[i][0]){
						b[i][0]=b[wzz][0]+1;
						b[i][1]=b[wzz][1];
					}
					else if(b[wzz][0]+1<=b[i][0]){
						b[i][1]+=b[wzz][1];
					}
					wzz--;
				}
				if (b[i][1]==2) ans++;
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}

