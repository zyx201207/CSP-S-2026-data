#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int a[N],n,m;
int b[N],k=0,m1[N],q1[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int q=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			if(a[i]>=a[i-1]){
				q++;
				q1[a[i]]=i;
			}
		}
		else q1[a[i]]=i;
	}
	if(q==n){
		for(int i=1;i<=m;i++){
			cout<<q1[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		    b[a[j]]++;
		    if(b[a[j]]>=2){
		    	for(int k=q1[a[j]];k<j;k++){
		    		b[a[k]]--;
				}
			}
			q1[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(b[j]>=1) m1[j]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<m1[i]<<" ";
	}
	return 0;
}
