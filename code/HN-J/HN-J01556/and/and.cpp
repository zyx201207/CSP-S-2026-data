#include<bits/stdc++.h>
using namespace std;
int l[200005];
int main(){
	int n,m,a,c=-1;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	sort(l,l+n,greater<int>());
	int b=l[0];
	for(int i=1;i<m;i++){
		b=b&l[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				if(l[i]&l[j]>c)c=l[i]&l[j];
			}
		}
	}
	cout<<max(b,c);
	return 0;
} 
