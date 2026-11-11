#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<int> a(n+3);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		long long ans=0,id=0;
		vector<int> b(n+3,0);
		for(int j=i-1;j<n;j++){
			bool f=false;
			for(int z=0;z<=id;z++){
				if(f)continue;
				if(b[z]==a[j]){
					for(int q=z;q<=id;q++){
						b[q]=0;
						f=true;
						id=z;
					}
				}
			}
			b[id++]=a[j];
		}
		for(int j=0;j<id;j++){
			if(b[j]==i)ans++;
		}
		cout<<ans<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

