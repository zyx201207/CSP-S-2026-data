#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],mmax=0,cnt=1,x[500001]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		x[i]=a[i]-a[i-1];
		//cout<<x[i]<<' ';
	}
	//cout<<endl;
	for(int i=2;i<=n;i++){
		int j=i;
		int g=x[j],mm=m;
		while(mm>=g&&j<=n){
					
			//cout<<i<<' ';
			mm-=g;
			j+=1;
			if(a[j]!=a[j+1]){
				g+=x[j];	
			}
			cnt++;			
			
		}
		//cout<<endl;
		mmax=max(mmax,cnt);
		cnt=1;
	}
	cout<<mmax;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
