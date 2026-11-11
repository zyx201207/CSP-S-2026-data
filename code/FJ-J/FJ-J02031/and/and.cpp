#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		int maxn=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((a[i]&a[j])>=maxn){
					maxn=(a[i]&a[j]);
				}
			}
		}
		cout<<maxn;
	}
	if(m==3){
		int maxn=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					if((a[i]&a[j]&a[k])>=maxn){
						maxn=(a[i]&a[j]&a[k]);
					}
				}
				
			}
		}
		cout<<maxn;
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
