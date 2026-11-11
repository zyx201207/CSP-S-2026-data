#include<bits/stdc++.h>
using namespace std;

int a[100005];
int main(){
	int cnt=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long b=a[i+1]-a[i];
		if(b<0) b=-b;
		
		if(m>=b*i){
			for(int j=1;j<=1;j++){
				a[j]=a[j+1];				
			}
			m-=b*i;
		}
		else{
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			cnt++;
		} 
		else{
			cout<<cnt+1;
			return 0;
		}
	}
	
	
	
	
	return 0;
} 


