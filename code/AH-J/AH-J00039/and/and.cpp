#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int max=0,n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>max)
			max=a[i];
		}
		cout<<max;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if((a[i]&a[i+1])>max)
			max=(a[i]&a[i+1]);
		}
		cout<<max;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				if((a[i]&a[j])>max&&i!=j)
					max=a[i]&a[j];
			}
		}
		cout<<max;
		return 0;
	}
	cout<<3;
	return 0;
}
