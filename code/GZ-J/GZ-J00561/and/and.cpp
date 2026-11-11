//石阡县文博中学 刘贝宁 GZ-00561
#include <bits/stdc++.h>
using namespace std;
int n,m;
int n1[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> n1[i];
	}
	if(m==2){
		int maxn=-1;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				
				if((n1[i]&n1[j])>maxn){
					maxn=(n1[i]&n1[j]);
				}
			}
		}
		cout << maxn;
	}
	
	if(m==1)	{
		int maxn=-1;
		for(int i=0;i<n;i++){
			if(maxn<n1[i]){
				maxn=n1[i];
			}
		}
		cout << maxn;
	}

	if(m==3){
		int maxn=-1;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int q=j+1;q<n;q++){
					if((n1[i]&n1[j]&n1[q])>maxn){
						maxn=(n1[i]&n1[j]&n1[q]);
					}	
				}
				
			}
		}
		cout << maxn;
	}
		
	
	return 0;
} 
