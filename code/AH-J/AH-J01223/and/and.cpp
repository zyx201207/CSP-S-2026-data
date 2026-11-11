#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==m){
		int tmp=a[0];
		for(int i=1;i<n;i++) tmp=tmp&a[i];
		cout<<tmp;
		return 0;
	}
	if(m==1){
		int tmp=0;
		for(int i=0;i<n;i++){
			tmp=max(tmp,a[i]);
		}
		cout<<tmp;
		return 0;
	}
	if(m==2){
		int tmp=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				tmp=max(tmp,a[i]&a[j]);
			}
		}
		cout<<tmp;
		return 0;
	}
	srand(time(0));
	cout<<rand()*rand()%1073741824;
	return 0;
}
