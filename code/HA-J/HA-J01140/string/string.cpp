#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,a[200005],k=0,gt=0;
	string g,b;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		scanf("%d",&g[i]);
	}
	for(int c=0;c<n;c++){
		for(int j=k;j<a[c]+k;j++){
		b[j]=g[c];
		}
			k+=a[c];
	}
		
		for(int i=0;i<k/2;i++){
			if(b[i]!=b[k-1-i]){
				gt+=1;
			} 
		}
	printf("%d",gt);
	return 0;
}
