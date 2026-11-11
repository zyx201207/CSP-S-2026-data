#include<bits/stdc++.h>
using namespace std;
int a[500005]={},a1[500005]={};
int n,m;
void aa(){
	for(int i=1;i<=n;i++){
		a1[i]=a[i];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int t[300005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		aa();
		for(int k=i,p;k<=n;k++){
			bool f=true;
			for(int j=0;j<k;j++){
				if(a1[j+1]==a[k]){
					f=false;
					p=j+1;
					break;
				} 
			}
			if(f){
				a1[k+1]=a[k];
			}else{
				for(int j=p;j<=k;j++){
					a1[j]=0;
				}
			}
		}
		for(int k=1;k<=n;k++){
			t[a1[k]]++;
			cout<<a1[k]<<' ';
		}
		cout<<endl;
	}
//	for(int i=1;i<=m;i++){
//		cout<<t[i]<<' ';
//	}
	return 0;
}
