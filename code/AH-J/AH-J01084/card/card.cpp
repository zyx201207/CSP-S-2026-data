#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],b1[300005],b2[300005],b3[300005];
void hanshu(long long p){
	int b5[300005],b6[300005];
	memset(b1,0,sizeof(b1));
	memset(b3,0,sizeof(b3));
	for(int i=p;i<=n;i++){
		if(b5[i]==1){
			b1[i]=b6[b5[i]]-1,b3[i]=i+1,b3[b6[b5[i]]-1]=i;
		}else{
			b5[a[i]]++,b6[b5[i]]=i,b1[i]=i-1,b3[i]=i+1;
		}
	}
	int i=p;
	while(i<=n){
		t[b2[i]]++;
		i=b3[i];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b2[i]=a[i];
	}
	for(int i=1;i<n;i++){
		hanshu(i);
	}
	t[a[n]]++;
	for(int i=1;i<=m;i++){
		if(i==m){
			cout<<t[i]<<" ";
		}else{
			cout<<t[i]-1<<" ";
		}
	}
	return 0;
}
