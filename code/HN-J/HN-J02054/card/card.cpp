#include<bits/stdc++.h>
using namespace std;
int ans[300005],q[500005],a[500005],r=0,b[300005],la[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		la[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		r=0;
		bool ca=1;
		int p=0;
		for(int j=i;j<=n;j++){
			if(la[a[j]]==j && ca){
				p++;
			}
			else{
				ca=0;
			}
			j=la[a[j]];
//			cout<<a[j]<<"	";
			if(b[a[j]]){
//				cout<<"a	";
//				cout<<b[a[j]]<<" "<<r<<" ";
				for(int k=b[a[j]]+1;k<=r;k++){
					b[q[k]]=0;
				}
				r=b[a[j]];
//				cout<<r;
			}
			else{
//				cout<<"b	";
				r++;
				q[r]=a[j];
				b[a[j]]=r;
			}
//			for(int j=1;j<=r;j++){
//				cout<<q[j]<<" ";
//			}cout<<"\n";
		} 
		int tot=1;
		for(int j=1;j<=r;j++){
			b[q[j]]=0;
			ans[q[j]]+=tot;
			if(tot<=p){
				tot++;
			}
//			cout<<q[j]<<" ";
		}
		i=i+p;
		for(int i=1;i<=m;i++){
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
} 
