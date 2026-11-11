#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end(),cmp);
	int maxx=-1;
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]&a[j]>maxx){
					maxx=a[i]&a[j];
				}
			}
		}
		cout<<maxx;
	}else{
		int o=a[0];
		cout<<a[0]<<' '<<a[1];
		for(int i=1;i<m;i++){
			
			o&=a[i];
		}
		cout<<o<<"\n";
	}
	
	return 0;
}
