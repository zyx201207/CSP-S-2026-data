#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],x[500005],y[300005],s[300005],yu[300005],yush[300005];
bool w=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			w=0;
		}
	}if(w){
		long long sum=0;
		for(int i=1;i<=n;i++){
			yu[a[i]]++;
			yush[a[i]]=yu[a[i]];
		}
		for(int i=1;i<=n;i++){
			yu[a[i]]-=1;
			if(yu[a[i]]%2==1){
				s[a[i]]++;
			}
		}for(int i=1;i<=n;i++){
			if(yush[a[i]]%2==1&&sum!=a[i]){
				sum=a[i];
				s[a[i]]+=i;
			}
		}for(int i=1;i<=m;i++){
			cout<<s[i]<<" ";
		}
	}else{
		for(int i=1;i<=n;i++){
			long long sum=0;
			for(int j=i;j<=n;j++){
				if(y[a[j]]!=0){
					for(int k=y[a[j]]+1;k<=sum;k++){
						y[x[k]]=0;
						x[k]=0;
					}
					sum-=(sum-y[a[j]]);
				}else{
					x[++sum]=a[j];
					y[a[j]]=sum;
				}
			}
			for(int j=1;j<=m;j++){
				s[x[y[j]]]++;
				x[y[j]]=0,y[j]=0;
			}
		}for(int i=1;i<=m;i++){
			cout<<s[i]<<" ";
		}
	}//yuanshenniubi
	return 0;
}
