//GZ-J00432 贵阳市第三十四中学 杨宗泽 
#include<bits/stdc++.h>
using namespace std;
long long n,m,s,a[200005],maxn,x,y;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=i){
				if((a[i]&a[j])>maxn){
					maxn=(a[i]&a[j]);
					x=a[i];
					y=a[j];
				}
			}
			//cout<<(a[i]&a[j])<<endl;
		}
	}
	if(m==2){
		cout<<maxn;
		return 0;
	}
	int xn=maxn;
	maxn=0;
	while(m!=0){
		a[x]=0;
		a[y]=0;
		int k=0;
		for(int i=1;i<=n;i++){
			if((xn&a[i])>maxn){
				maxn=(xn&a[i]);
				k=i;
			}
		}
		a[k]=0;
		m--;
	}
	return 0;
}
