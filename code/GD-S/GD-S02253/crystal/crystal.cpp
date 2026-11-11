#include <bits/stdc++.h>
using namespace std;

long long n,m,shuu;
int a[500005];

void f(int k,int l,int r,bool q){
	if(l<=0||r>n){
		return;
	}
	long long t=m,u=1;
	while(t>0){
		if(a[k]-a[l]<a[r]-a[k]&&l-1>0){
			t-=abs(a[k]-a[l]);
			l--;
			u++;
		}
		else if(a[k]-a[l]>a[r]-a[k]&&r+1<=n){
			t-=abs(a[r]-a[k]);
			r++;
			u++;
		}
		else if(l-1>0){
			t-=abs(a[k]-a[l]);
			l--;
			u++;
		}
		else if(r+1<=n){
			t-=abs(a[r]-a[k]);
			r++;
			u++;
		}
		else{
			t=0;
			if(q){
				f(k-1,k-2,k,q);
			}
			else{
				f(k+1,k,k+2,q);
			}
		}
		if(t<0){
			if(q){
				f(k-1,k-2,k,q);
			}
			else{
				f(k+1,k,k+2,q);
			}
		}
	}
	shuu=max(shuu,u);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}

	f(n/2,n/2-1,n/2+1,0);
	f(n/2-1,n/2-1-1,n/2+1-1,1);
	cout<<shuu;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
