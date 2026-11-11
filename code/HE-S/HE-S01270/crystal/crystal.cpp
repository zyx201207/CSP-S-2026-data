#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%ld %ld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%ld",&a[i]);
	}
	int k=0;
	int p=n/2+1;
	for(int i=0;i<p;i++){
		int s=a[p]; 
		for(int j=0;j<m;j++){
			int cnt=0;
			while(1){
				if(a[i]!=a[p]){
				    a[i]++;
				    cnt++;
				}else{
					k++;
					
				    break; 
				} 
			}
			if(cnt=m){
				break;
			}
			
		}	
	}
	printf("%d",k);
	return 0;
}
