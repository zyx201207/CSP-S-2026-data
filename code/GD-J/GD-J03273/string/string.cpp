#include<bits/stdc++.h>
using namespace std;
long long n,i,k,p,q,ans,ans2;
string a[10086],b;
void change(int x,int y){
	for(int i=1;i<=p;i++){
		if(a[i]!=a[y]){
			a[y]=a[i];
			ans++;
			y--;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	k=1;
	while(n--){
		cin>>i>>b;
		while(i--){
			a[k]=b[0];
			k++;
		}
	}
	k=k-1;
	if(k%2==0){
		p=k/2;
		q=k;
		change(p,q);
	}else{
		p=k/2;
		q=k;
		change(p,q);
	}
	cout<<ans;
	return 0; 
}

