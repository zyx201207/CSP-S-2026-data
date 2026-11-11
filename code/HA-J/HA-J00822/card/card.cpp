#include<bits/stdc++.h>
using namespace std;
long long a[30005], b[30005],c[30005];int n,ans,h,num,nu,j;

int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
int m,k=-1;
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
}for(int as=0;as<n;as++){
for(int i=as;i<n;i++){int cmp=0;
for(int j=0;j<=k;j++){
	if(b[j]==a[i]){
		k=j;
		cmp=1;
	}
}if(cmp==0){
	k++;
	b[k]=a[i];
}
}for(int h=0;h<=k;h++){
	c[b[h]-1]++;
}for(int g=0;g<n;g++){
	b[g]=0;k=0;
}
}


for(int i=0;i<m;i++){
	cout<<c[i]<<" ";
}
	return 0;
}
