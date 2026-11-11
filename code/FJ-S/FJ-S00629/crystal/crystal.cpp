#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int a[100000]={ };
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=1;
	int flag=0;
	int b[10000]={ };
	int min=2147483647;
	int x=0;
	int z=1;
while(m>0){
	
		b[0]=a[x];
	for(int i=z;i<n;i++){
		b[i]=a[i]-a[i-1];
	
	}
	min=2147483647;
	flag=0;
	for(int i=z+1;i<n;i++){
		if(b[i]<min){
			min=b[i];
			flag=i;
		}
	}
	
	
	m=m-min*ans;
	int yd=a[flag];
	while(flag--){
		a[flag]=yd;
	}
	x++;
	z++;
	ans++;
	

}
	
	
	
	cout<<ans;
	return 0;
	
}
