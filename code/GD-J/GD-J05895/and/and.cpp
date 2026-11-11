#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],ans=0,w;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	while(w){
		for(int i=0;i<n;i++){
			if(a[i]<1<<w)
				break;
			if(a[i+m]>=1<<w){
			}
				ans+=a<<w;
		}
	}
	return 0;
} 
