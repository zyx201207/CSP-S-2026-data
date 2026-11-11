#include<bits/stdc++.h>
using namespace std;
long long a[100001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,max=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	else if(m==n){
		int s=a[1];
		for(int i=2;i<=n;i++){
			s=s&a[i];
		}
		cout<<s;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((a[i]&a[j])>max)max=a[i]&a[j];
			}
		}	
		cout<<max;
		return 0;
	}
	else{
		int s=a[1];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=m+i;j++){
				s=s&a[j];
				if(s>max)max=s; 
			}
		}
		cout<<max;
		return 0;
	}                                                
} 
