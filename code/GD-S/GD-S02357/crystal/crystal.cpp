#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n,m,d=0,e=0,c=0;
	cin>>n>>m;
	int a[n+1];
	int b[n+1],f[n];
	for(int i=1;i<=n;i++){
		f[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i==1){
			if(a[i]==a[1]){
				f[i]++;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				b[j]=abs(a[j]-a[i]);
			}
			sort(b,b+n);
			for(int j=1;j<=n;j++){
				m-=b[j];
				f[i]++;
				if(m<=0)
					break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		c=max(f[i],c);
	}
	cout<<c;
	return 0;
}
