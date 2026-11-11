#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+6;
int a[N];
int n,m;
int maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>maxn){
					maxn=(a[i]&a[j]);
				}
			}
		}
	}
	cout<<maxn;
	return 0;
}
