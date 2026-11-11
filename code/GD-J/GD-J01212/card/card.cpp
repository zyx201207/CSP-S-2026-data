#include<bits/stdc++.h>
using namespace std;
long long m,n,c[200005],b[200005],cnt[200005],t[200005];
bool pos(long long a,int b){
	for(int i=1;i<=b;i++){
    	if(c[i]==a && t[c[i]]==1) {
    		return 1;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int l1=1;l1<=n;l1++){
    		t[l1]=0;b[l1]==0;
		}
    	for(int j=i;j<=n;j++){
    		b[j]=c[j];
    	if(pos(b[j],j)==1){
    		for(int l=1;l<j;l++){
    		t[b[l]]=0;b[l]==0;
		}
		t[c[j]]=1;
	}
	}
	for(int l2=1;l2<=n;l2++){
    		cnt[b[l2]]++;
		}
}
for(int i=1;i<=m;i++){
    		cout<<cnt[i]<<' ';
		}
	return 0;
}

