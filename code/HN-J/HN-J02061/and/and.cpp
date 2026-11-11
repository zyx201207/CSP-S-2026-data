#include<bits/stdc++.h>
using namespace std;
long long n,m,a[676767],b[676767][676767];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	if(m==n){
		long long x=a[1];
		for(int i=2;i<=n;i++)
		    x&=a[i];
		cout<<x;
	}else if(m==1){
		long long y=0;
		for(int i=1;i<=n;i++)
		    if(a[i]>y) y=a[i];
		cout<<y;
	}else{
		for(int i=1;i<=m;i++)
			for(int j=i;j<=n;j++){
				if(i==1) b[i][j]=a[j];
				else{
					int k=0;
					for(int x=1;x<j;x++){
						int t=a[j]&b[i-1][x];
						if(t>k) k=t;
				    }
				    b[i][j]=k;
				}
			}
		long long y=0;
		for(int j=1;j<=n;j++) if(b[m][j]>y) y=b[m-1][j];
		cout<<y;
	}
	fclose(stdin);fclose(stdout);
	
	return 0;
}
