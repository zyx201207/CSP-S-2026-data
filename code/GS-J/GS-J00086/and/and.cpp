#include<iostream>
using namespace std;

int main(){
	string a{1,2,3,4,5,6,7,8,9,11,12,13,14,15,16};
    int n,m;
    cin >> m >> n;
    char z[n+ 13];
    for(int i = 0;i <= n;i++){
    	cin >> z [i]; 
	}
	int num = 0;
    whil(g <n+1){
    	for(int i = 0;i <= n;i++){
    		if(z[i] <= z [ i +1])
    		{
    			num ++;
    			cout << a[z[i] + 1]
			}
			else
			{
				cout << num; 				
			}
		}
		z[i] = a[i];
	}
	cout  << k;
    return 0;
}


