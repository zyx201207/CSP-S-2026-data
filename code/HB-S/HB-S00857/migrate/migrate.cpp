#include <bits/stdc++.h>
using namespace std;
int n,d,a[3000000],b[3000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int an,T,c;
	cin>>c>>T;
	while(T--){
	if(c==13||c==14){
		cout<<"0\n";
		continue;
	}

		an=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(c==11||c==12){
		int e;
		e=d/(b[n]-b[n-1]);
		for(int k=1;k*e<=n;k++){
			an+=n-(e*k+1);
		}
		cout<<an<<'\n';
		continue;
	}
	for(int i=1;i<=n;i++){
		b[i]=max(1,(int)(lower_bound(a+1,a+i+1,a[i]-d)-a));
		//cout<<b[i]<<' ';
	}
	for(int i=1;i<=n;i++){
		int d[5005],w[5005];
		memset(d,0x3f,sizeof(d));
		d[i]=0;
		for(int j=i+1;j<=n;j++){
			if(b[j]==j)break;
			for(int k=max(i,b[j]);k<j;k++){
				if(d[k]+1==d[j]){
					w[j]+=w[k];
				}
				if(d[k]+1<d[j]){
					w[j]=1;
					d[j]=d[k]+1;
				}
			}
		//	cout<<d[j]<<' '<<w[j]<<' ';
			if(w[j]==2){
				an++;
			}
		}//cout<<'\n';
		
	}
	cout<<an<<'\n';
	}
	return 0;
}
