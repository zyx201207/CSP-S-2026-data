#include<bits/stdc++.h>
using namespace std;
freopen("crystal.in","r",std.in);
freopen("crystal.out","w",std.out);
int n,m,a[10010];
int main (){
    cin >> n >>m;
    int sum =0;
    int b=0,c= 0;
	int num =0;
    for(int i = 1; i <= n; i ++){
    	cin >> a[i];
    	if(m>0){
    		b=a[i];
    		c=a[i]+1;
    		if(b<=c){
    			sum+=b - c;
			}else{
				sum+=c-b;
			}
		}else{
			break;
		}
		if(b == c){
			num +=1;
		}
    }
    for(int i = 1; i <= n; i ++){
    	if(a[i]==a[i+1]){
    		num+=1;
		}
    }
	cout << num+1;
	return 0;
} 
