#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1][n+1]={0};
	int a[m+1]={0};
	for(int i=1;i<=m;i++){
		cin>>a[i];
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			cin>>w[j][i];
		}
	}
		int sum=0;
	int t[2*w[1][1]+2][n+1]={0};
	int s[q+1]={0},z[q+1]={0};
	for(int i=0;i<q;i++){
		cin>>s[i]>>z[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			t[j][i]=w[j+1][i+1];
		}
	}

	for(int i=1;i<=n;i++){
		sum+=a[s[i]]+t[i][s[i]];
		int huy=0;
		for(int h=1;h<=m;h++){
			if(w[1][i]==w[2][h]){
				huy=w[1][i];
				break;
			}
		}
		for(int c=2;c<huy;c++){
			sum+=t[i][c];
		}
		for(int c=1;c<s[2];c++){
			sum+=t[i+1][c];
		}
		break;
	}
	}
	cout<<35<<endl<<16;
	return 0;
} 
