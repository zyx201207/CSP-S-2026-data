#include <iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,num;
	int max = 0;
	cin >>n>>m;
	int arr[n];
	for (int i = 0;i < n;i++){
		cin >>arr[i];
	}
	int L = 0,R = n-1;
	
	if (m == 1){
		for (int i = 0;i < n;i++){
		 	if (max < arr[i]){
		 		max = arr[i];
			 }
		}
		cout <<max;
	}
	if (m == 2){
		for (int i = 0;i < n-1;i++){
			for (int j = i+1;j < n;j++){
				num = (arr[i] & arr[j]);
				if (num > max){
					max = num;
				}
			}
		}
		cout <<max;
	}
	if (m == 3){
		for (int i = 0;i < n-2;i++){
			for (int j = i+1;j < n-1;j++){
				for (int k = j+1;k < n;k++){
					num = (arr[i] & arr[j] & arr[k]);
					if (num > max){
						max = num;
					}
				}
			}
		}
		cout <<max;
	}
	if (m == 4){
		for (int i = 0;i < n-3;i++){
			for (int j = i+1;j < n-2;j++){
				for (int k = j+1;k < n-1;k++){
					for (int l = k+1;l < n;l++){
						num = (arr[i] & arr[j] & arr[k] & arr[l]);
						if (num > max){
							max = num;
						}
					}
				}
			}
		}
		cout <<max;
	}
	if (m == 5){
		for (int i = 0;i < n-4;i++){
			for (int j = i+1;j < n-3;j++){
				for (int k = j+1;k < n-2;k++){
					for (int l = k+1;l < n-1;l++){
						for (int h = l+1;h < n;h++){
							num = (arr[i] & arr[j] & arr[k] & arr[l] & arr[h]);
							if (num > max){
								max = num;
							}
						}
					}
				}
			}
		}
		cout <<max;
	}
	
	return 0;
}






