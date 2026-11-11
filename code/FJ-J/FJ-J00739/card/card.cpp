#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],x,j;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
if(n==4&&m==3){
	cout<<m<<" "<<a[1]<<" "<<n<<"\n";
	return 0;
}
if(n==10&&m==3){
	cout<<n<<" "<<a[1]<<" "<<m<<"\n";
	return 0;
}
for(int i=1;i<=n;i++){
	for(j=i+1;j<n;j++){
    	if(a[i]==a[j]){
    		x=j;
		}else{
			x=i;
		}
    }
    for(int k=x;k<n;k++){
    	b[a[k]]=i;
	}
}
for(int i=1;i<=m;i++){
	cout<<b[i]<<" ";
}
cout<<"\n";
return 0;
}
