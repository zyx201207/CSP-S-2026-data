#include <bits/stdc++.h>
using namespace std;
long long q,w,e,a[1010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>q>>w;
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	if(w==1){
		sort(a+1,a+1+q);
		cout<<a[q];
		return 0;
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=q;j++){
			if(i!=j){
				e=max(e,a[i]&a[j]);
			}
		}
	}
	cout<<e;
	return 0;
}
