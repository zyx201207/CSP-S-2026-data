#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	int nn=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		t[a[i]]++;
	}
	if(m==2){
		for(int i=n;i>0;i--){
			if(a[i]==a[i-1]){
				i--;
				n-=2;
			}else if(a[i]==a[i-2]){
				i-=2;
				n-=3;
			}
		} 
		if(n==2){
			printf("1 1");
		}else if(a[nn]==1&&n==1){
			printf("1 0");
		}else if(a[nn]==0&&n==1){
			printf("0 1");
		}else if(n==0){
			printf("0 0");
		}
	}else{
		for(int i=1;i<n;i++){
			if(a[i]==a[i+1]){
				t[a[i]]-=2;
				i++;
			}
		} 
		for(int i=1;i<=m;i++){
		printf("%d ",t[i]);
		} 
	}
//	cout<<n;
}
