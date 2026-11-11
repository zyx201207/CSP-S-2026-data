#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],ans,b[500005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n,cmp); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[j]=a[i]-a[j];
		}
		for(int j=1;j<=n;j++){
			if(m>=c[j]){
			m-=c[j];
			b[i]++;
		}
		else{
			break; 
		}
		}
		b[i]=b[i]-i+1;
	}
	sort(b+1,b+1+n,cmp);
	cout<<b[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
