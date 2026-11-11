#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long d[N][2],a[N];
int main(){
	long long n,m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i][1]=m;
	}
	sort(a+1,a+n+1);
	d[1][0]=1;
	for(int i=2;i<=n;i++){
		if(d[i][1]>(a[i]-a[i-1])*d[i-1][0]){
			d[i][0]=d[i-1][0]+1;
			d[i][1]=d[i-1][1]-(a[i]-a[i-1])*d[i-1][0];
		}
		else if(i>2){
			if(d[i-1][1]>d[i][1]-(a[i]-a[i-2])*d[i-2][0]){
				d[i][0]=d[i-1][0];
				d[i][1]=d[i-1][1];
				a[i]=a[i-1];
			}
			else{
				d[i][0]=d[i-2][0]+1;
				d[i][1]=d[i][1]-(a[i]-a[i-2])*d[i-2][0];
			}
		}
		else{
			d[i][0]=d[i-1][0];
			d[i][1]=d[i-1][1];
			a[i]=a[i-1];
		}
		for(int i=1;i<=n;i++){
			cout<<d[i][0]<<" ";
		}cout<<endl;
	}cout<<endl;
	cout<<d[n][0];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
