#include<bits/stdc++.h>
using namespace std;
int a[5000010],b[5000010];
int x=0,maxx=0,maxi=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);		
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			x++;
		}
		else{
			if(x>maxi){
				maxx=a[i-1];
				maxi=x;
			}
		}
	}
	if(maxx==0){
		maxx=a[n/2+1];
	}	
	for(int i=1;i<=n;i++){
		if(a[i]<=maxx){
			b[i]=maxx-a[i];
		}
		else{
			b[i]=-1;
		}
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		if(b[i]>=0&&m-b[i]>=0){
			m-=b[i];
			num++;
		}
	}
	cout<<num;
	return 0;
}
