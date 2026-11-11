#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int list[n]={};
	int num[m]={};
	int num_time[m]={};
	int ans[m]={};
	for(int i=0;i<n;i++){
		cin >>list[i];
		num[list[i]-1]++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			num_time[j]=num[j];
		}
		int j=i;
		while(j!=n){
			if(num_time[list[j]-1]=1){
				ans[list[j]-1]+=1;
				num_time[list[j]-1]--;
				j++;
			}
			else{
				while(num_time[list[j]-1]!=1){
					num_time[list[j]-1]--;
					int a=j+1;	
					while(list[j]!=list[a]){
						num_time[list[a]-1]--;
						a++;
					}
					j=a;
					num_time[list[j]-1]--;				
				}
				ans[list[j]-1]+=1;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout << ans[i];
	}
	return 0;
}
