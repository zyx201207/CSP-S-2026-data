#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200000];
//bool is2(int a){
//	for(int i=1;i<=30;i++){
//		if(a==pow(2,i)-1){
//			return true;
//		}
//	}
//	return false;
//}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen("and1.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxx=-1;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	if(m==1){
		int maxs=-1;
		for(int i=0;i<n;i++){
			maxs=max(maxs,a[i]);
		} 
		cout<<maxs;
		return 0;
	}
	else if(m==n){
		int and1=a[0];
		for(int i=1;i<n;i++){
			and1&=a[i];
		} 
		cout<<and1;
		return 0;
	}
//	int now=0;
//	for(int k=0;k<m;k++){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
//				if(is2(a[j])==true)
				maxx=max(maxx,a[i]&a[j]);
//				now=maxx;
			}
		}
//	}
	cout<<maxx;
    return 0;
}

