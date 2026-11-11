#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; 
	cin>>n;
	long long sa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sa+=a[i];
	}
	long long l=sa/2;
	long long k=n;
	long long sum=0;
	for(int i=1;i>0;){
		int o=min(a[i],a[k]);
		if(o<l){
			if(c[i]!=c[k]){
				if(a[i]<a[k]){
					l-=a[i];
					sum+=a[i];
					a[k]-=a[i];
					i++;
				}else{
					if(a[i]==a[k]){
						l-=a[i];
						sum+=a[i];
						k--;
						i++;
					}else{
						if(a[i]>a[k]){
							l-=a[k];
							sum+=a[k];
							a[i]-=a[k];
							k--;
						}	
					}
				}	
			}else{
				if(a[i]<a[k]){
					l-=a[i];
					a[k]-=a[i];
					i++;
				}else{
					if(a[i]==a[k]){
					l-=a[i];
					k--;
					i++;
					}else{
						if(a[i]>a[k]){
						l-=a[k];
						a[i]-=a[k];
						k--;
						}
					}
				}	
			}
		}else{
			if(c[i]!=c[k]){
				sum+=l;
				break;
			}else{
				break;
			}
		}
	}
	cout<<sum;
	return 0;
} 
