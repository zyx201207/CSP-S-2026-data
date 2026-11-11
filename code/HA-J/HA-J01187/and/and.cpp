#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 	int n,m;
 	cin>>n>>m;
 	for(int i=0;i<n;i++){
 		cin>>a[i];
 	}
 	sort(a,a+n);
 	if(m==1){
 		cout<<a[0];
 	}else if(m==2){
 		int p=-1;
 		for(int i=0;i<n;i++){
 			for(int j=i+1;j<n;j++){
 				int t=a[i]&=a[j];
 				p=max(p,t);
 			}
 		}
 		cout<<p;
 	}else if(m==n){
 		int t=a[0];
 		for(int i=1;i<n;i++){
 			t&=a[i];
 		}
 		cout<<t;
 	}else{
 		int t=a[0];
 		for(int i=0;i<m;i++){
 			t&=a[i];
 		}
 		cout<<t;
 	}
 	
	return 0;
}
