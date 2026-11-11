#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005],b[100005];
long long tong[100005];
long long d;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int q=1;q<=n;q++){
for(int i=q+1;i<=n;i++){
	int wei=0;
	bool e=0;
	for(int j=0;j<=n;j++){
		if(b[j]==a[i]){e=1;wei=j;break;}
	}
	if(e==0){b[d]=a[i];d++;}
	else if(e==1){
	for(int k=wei;k<=n;k++){
		b[k]=0;
	}
	b[wei]=a[i];
}
}
for(int w=0;w<=d;w++){
	tong[b[w]]++;
}
}
for(int i=1;i<=m;i++){
	cout<<tong[i]<<" ";
}
	return 0;
}
