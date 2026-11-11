//GZ-J00327 遵义市第十九中学 张锣址杨 
#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int pai[n+5],end[m+5]={0};
	for(int i = 0;i < n;i++){
		cin>>pai[i];
	}
	for(int i =0 ;i <n;i++){
	int zhuo[n+5]={0};
		for(int j = i,l=0;j<n;j++,l++){
			for(int k=0;k<n;k++){
				if(zhuo[k]==pai[j]){
					for(int p=k;p<n;p++){
						zhuo[p]=0;
					}
					l=k;
					break;
				}
			}
			zhuo[l]=pai[j];
		}
		for(int j =1;j <= m;j++){
			for(int k=0;k<n;k++){
				if(zhuo[k]==j){
					end[j]++;
					break;
				}
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << end[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

