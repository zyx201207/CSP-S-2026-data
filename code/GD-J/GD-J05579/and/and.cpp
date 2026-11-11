#include<bits/stdc++.h>
using namespace std;
int n,m,num=0,mun=0,b;
long long a[100001];

//void dfs(int h[100001],int x){
//	if(x==1){
//		
//	}
//	
//	
//}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0; i<n; i++){
		cin>>a[i];
	} 
	if(m==1){
		for(int i = 0;i<n;i++){
			if(a[i]>num){
				num=a[i];
			} 
		}
		cout<<num;
		return 0;
	}
	if(m==2){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(i==j){
					continue;
				}
				if(i<j){
					continue;
				}
				if((a[i]&a[j])>mun){
					mun=a[i]&a[j];
//					cout<<mun<<endl;
				}
			}
		}
		cout<<mun;
		return 0;
	}
	if(m==n){
		int ans=a[1]&a[0];
		for(int i = 2;i<n; i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int man=a[1]&a[0];
		for(int i = 2;i<n-1; i++){
			man=man&a[i];
		}
		int man1=a[0];
		for(int i = 1;i<n; i++){
			for(int j = 1; j<n;j++){
				if(j==i){
					continue;
				}
				man1=man1%a[i];
			}
			if(man1>b){
				b=man1;
			}
		}
		cout<<max(b,man);
		return 0;
	}
	
	
	return 0;
} 
