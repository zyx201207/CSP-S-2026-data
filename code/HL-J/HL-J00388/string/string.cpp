#include<bits/stdc++.h>
using namespace std;

int n;
int num[200005];
char hui[200005];
bool shen = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
    cin >> n;
    
    for(int i = 1;i <= n;i++){
    	cin >> num[i] >> hui[i];
	}
	
	for(int i = 1;i <= n;i++){
    	if(hui[i] == hui[i + 1]){
    		cout << 0;
		}else{
			shen = 0;
			break;
		}
	}
	if(shen != 1){
		cout << n * num[1] / 2;
	}
	return 0;
} 
