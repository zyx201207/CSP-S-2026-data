#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int s=a[1];
		for(int i=2;i<=n;i++){
			s=s&a[i];
		}
		cout<<s;
		return 0;
	}else if(m==1){
		int s=0;
		for(int i=1;i<=n;i++){
			s=max(s,a[i]);
		}
		cout<<s;
		return 0;
	}else if(m==2){
		int s=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int c=a[i]&a[j];
				s=max(s,c);
			}
		}
		cout<<s;
		return 0;
	}else{
		cout<<0;
	}
	return 0;
}
