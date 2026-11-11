//GZ-J00589 遵义市第四初级中学 蒋子涵
#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
struct box{
	int sl;
	char zm;
};
box a[200005]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sl;
		cin>>a[i].zm;
	}
	int l=1,r=n;
	while(l<=n){
		if(a[l].zm==a[r].zm){
			if(a[l].sl>=a[r].sl){
				a[l].sl-=a[r].sl;
				a[r].sl=0;
			}else{
				a[r].sl-=a[l].sl;
				a[l].sl=0;
			}
			if(a[r].sl==0) r-=1;
			if(a[l].sl==0) l+=1;
			continue;
		}else{
			if(a[l].sl>=a[r].sl){
				int k=min(a[l].sl,a[r].sl);
				sum+=k;
				a[l].sl-=k;
				a[r].sl=0;
			}else{
				int k=min(a[r].sl,a[l].sl);
				sum+=k;
				a[r].sl-=k;
				a[l].sl=0;
			}
			if(a[r].sl==0) r-=1;
			if(a[l].sl==0) l+=1;
			continue;
		}
	}
	cout<<sum;
	return 0;
}
