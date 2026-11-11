#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>m>>n;
	vector<int> a(n);
	vector<int> ans(n);
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		vector<bool> t(n);
		int s=i;
		for(int j=i;j<m;j++){
			if(t[a[j]-1]==1){
				while(a[s]!=a[j]){
					s++;
				}
				for(;s<j;s++){
					t[a[s]-1]=0;
				}
			}else{
				t[a[j]-1]=1;
			}
		}
//		cout<<s<<" ";
		for(int j=s;j<m;j++){
			ans[a[j]-1]++;
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
