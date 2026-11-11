#include<iostream>
#include<cstdio>
using namespace std;
long long And[200001], a[200001];
int main(){
	int n, m];
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		int max=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int an=(a[i]&a[j]);
				if(an>max){
					max=an;
				}
			}
		}
		cout<<max;
	}else if(m==3){
		int max=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int an=(a[i]&a[j]&a[k]);
				if(an>max){
					max=an;
				}
				}
			}
		}
		cout<<max;
	}else if(m==4){
		int max=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int h=k+1;h<n;h++){
						int an=(a[i]&a[j]&a[k]&a[h]);
				if(an>max){
					max=an;
					}
					
				}
				}
			}
		}
		cout<<max;
	}else{
		cout<<30;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
