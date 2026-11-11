#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cnt=0;
	int t;
	while(m>0){
		for(int i=1;i<=n;i++){
			if(a[i]<a[i+1]){
				t=i;
				break;
			}
		}
		if(m>=t){
			for(int i=1;i<=t;i++){
				a[i]++;
				m--;
			}
		}else{
			m=0;
		}	
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			cnt++;
		}
	}
	cnt++;
	printf("%d",cnt);
	return 0;
} 
