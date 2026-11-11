#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
char a[10005],a1[10005];
int cnt=0;
int non(){
	int f=1;
	for(int i=ans-1;i>=1;i--){
		a1[f]=a[i];
		f++;
	}
	int fi=1;
	for(int i=1;i<=ans-1;i++){
		if(a[i]!=a1[i]){
			fi=0;
		}
	}
	if(fi==1){
		return 1;
	}
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int c;char b;
		cin>>c>>b;
		for(int i=ans;i<=ans+c;i++){
			a[i]=b;
		}
		ans=c+ans;
	} 
	if(non()==1){
		cout<<"0";
		return 0;
	}
	
	return 0;
}
	
