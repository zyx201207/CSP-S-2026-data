#include<bits/stdc++.h>
using namespace std;
int n,a[500005],mi,b[500005],x,k,sum,num,c; 
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n%2==0)mi=a[n/2];
	else if(n%2==1)mi=a[n/2+1];
	for(int i=1;i<=n;i++){
		x=mi-a[i];
		if(x<0)x=-x;
		b[i]=x;
	}
	sort(b+1,b+n+1);
	for(int i=1;1==1;i++){
		if(b[i]==0){
			num++;
		}else break;
	}
	for(int i=1;m>0;i++,num--){
		if(b[i]==0 && num>=0){
			sum++;
			m=m-b[i];
		}else if(b[i]==0){
			break;
		}else if(m>=b[i]){
			sum++;
			m=m-b[i];
		}else if(m<b[i]){
			break;
		}
	
	}
	cout<<sum;
	return 0;
} 
