#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int sum=0;
	for(int i=1;i<=n;i++){
		 cin>>a[i];
	}
	for(int q=1;q<=n;q++){
		for(int o=1;o<=q;o++){
			if(a[q]=sum+q){
				sum++;
			}
		}
	}
	cout<<sum/3;
	return 0;
}

