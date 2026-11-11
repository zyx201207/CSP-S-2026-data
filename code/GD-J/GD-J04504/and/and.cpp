#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int f=1<<30;f>0;f>>=1){
		int k=0,j=1;
		for(int i=1;i<=n;i++){
			int c=((a[i]&f)>0?1:0);
			if(c==1){
				k++;
			}else b[j++]=i;
		}
		if(k>=m){
			sum+=f;
			for(int i=1;i<j;i++) a[b[i]]=0;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
