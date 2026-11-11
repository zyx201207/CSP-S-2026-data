#include<bits/stdc++.h>
using namspace std;
int n,m,cnt = 1;
int a[100005] = {};
int b[100005] = {};
int c[100005] = {};
int main(){
	frepen("travel.in","r",stdin);
	frepon("travel.out","w".stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cout<<a[i];
	}
	cout<<endl;
	for(int i = 1; i <= n;i++){
		if(b[a[i]] == 0){
			n[cnt] = a[i];
			b[a[i] = cnt;
			cnt++;
		}else{
			cnt = b[a[i]];
			cnt++;
		}
			for(int i=k;k<=cnt,k++){
				cout<< [n][k] <<" ";
				ans[n][k]++;
			}
			
			cout<<endl<<endl;
			for(int k = 1;k< =m;k++)cout<<b[k]<<" ";
		}
		cout<<endl;
		cnt = 1;
		memset(b, 0 , sizeof[b]);
		memset(b, 0 , sizeof[b]);
	}

	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	
	}
	
	return 0;
}
