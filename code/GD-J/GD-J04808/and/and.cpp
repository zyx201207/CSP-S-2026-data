#include<bits/stdc++.h>
using namespace std;
int main(){
//	frepon("and.in",'r',stdin);
//	frepon("and.out",'w',stdout);
	int n,m,a[200000],maxp=-1;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(m == 2){
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				if((a[i]&a[j])>maxp){
					maxp = (a[i]&a[j]);
				}
			}
		}
		cout<<maxp;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxp){
				maxp = a[i];
			}
		}
		cout<<maxp;
	}
	
	return 0;
//	fclose(stdin);
//	fclose(stdout);
}
